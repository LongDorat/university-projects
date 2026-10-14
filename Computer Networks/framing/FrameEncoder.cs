using System.Text;

namespace Framing;

/// <summary>
/// Streams an input stream into frames and writes each frame to a text writer as a hexadecimal line.
/// </summary>
/// <remarks>
/// The encoder never buffers the whole input. It reads at most one frame worth of data at a time,
/// so memory usage stays constant regardless of the input size. The final frame is padded with
/// <c>0x00</c> bytes so that every frame carries exactly <see cref="FrameOptions.FrameSize"/> data
/// bytes, even when the input length is not an exact multiple of the frame size.
/// </remarks>
public sealed class FrameEncoder
{
    private readonly FrameOptions _options;

    /// <summary>
    /// Initializes a new instance of the <see cref="FrameEncoder"/> class.
    /// </summary>
    /// <param name="options">The framing options that describe how frames are produced.</param>
    /// <exception cref="ArgumentNullException">Thrown when <paramref name="options"/> is <see langword="null"/>.</exception>
    public FrameEncoder(FrameOptions options)
    {
        ArgumentNullException.ThrowIfNull(options);
        _options = options;
    }

    /// <summary>
    /// Reads the input stream to the end and writes every produced frame to the output writer.
    /// </summary>
    /// <param name="input">The stream that supplies the raw data.</param>
    /// <param name="output">The writer that receives one hexadecimal frame per line.</param>
    /// <param name="cancellationToken">A token used to cancel the operation.</param>
    /// <returns>A task that completes when the whole input has been framed.</returns>
    /// <exception cref="ArgumentNullException">
    /// Thrown when <paramref name="input"/> or <paramref name="output"/> is <see langword="null"/>.
    /// </exception>
    public async Task EncodeAsync(Stream input, TextWriter output, CancellationToken cancellationToken = default)
    {
        ArgumentNullException.ThrowIfNull(input);
        ArgumentNullException.ThrowIfNull(output);

        byte[] dataBuffer = new byte[_options.FrameSize];
        byte[] frameBuffer = new byte[_options.FrameSize + 2 + (_options.UseErrorCorrection ? 1 : 0)];

        while (true)
        {
            int bytesRead = await ReadFrameAsync(input, dataBuffer, cancellationToken).ConfigureAwait(false);
            if (bytesRead == 0)
            {
                break;
            }

            // Zero any unused tail so a short final frame is padded with 0x00 bytes.
            if (bytesRead < dataBuffer.Length)
            {
                Array.Clear(dataBuffer, bytesRead, dataBuffer.Length - bytesRead);
            }

            int frameLength = BuildFrame(dataBuffer, frameBuffer);
            await output.WriteLineAsync(FormatHex(frameBuffer.AsSpan(0, frameLength))).ConfigureAwait(false);
            await output.FlushAsync(cancellationToken).ConfigureAwait(false);
        }
    }

    /// <summary>
    /// Fills the buffer with as many bytes as possible, stopping early only at the end of the stream.
    /// </summary>
    /// <param name="input">The stream to read from.</param>
    /// <param name="buffer">The buffer to fill.</param>
    /// <param name="cancellationToken">A token used to cancel the read.</param>
    /// <returns>The number of bytes written to the buffer. Zero means the end of the stream was reached.</returns>
    private static async Task<int> ReadFrameAsync(Stream input, Memory<byte> buffer, CancellationToken cancellationToken)
    {
        int total = 0;
        while (total < buffer.Length)
        {
            int read = await input.ReadAsync(buffer[total..], cancellationToken).ConfigureAwait(false);
            if (read == 0)
            {
                break;
            }

            total += read;
        }

        return total;
    }

    /// <summary>
    /// Builds a single frame from the supplied data.
    /// </summary>
    /// <param name="data">
    /// The raw data bytes for this frame. The span is expected to hold exactly
    /// <see cref="FrameOptions.FrameSize"/> bytes; any unused positions are assumed to already be zero.
    /// </param>
    /// <param name="destination">
    /// The buffer that receives the frame. It must be large enough for the start byte, the data,
    /// the optional LRC byte and the end byte.
    /// </param>
    /// <returns>The number of bytes written to <paramref name="destination"/>.</returns>
    private int BuildFrame(ReadOnlySpan<byte> data, Span<byte> destination)
    {
        destination[0] = _options.StartByte;

        Span<byte> encodedData = destination.Slice(1, data.Length);
        for (int i = 0; i < data.Length; i++)
        {
            encodedData[i] = _options.UseErrorCorrection ? ErrorCorrection.AddVrc(data[i]) : data[i];
        }

        int index = 1 + data.Length;
        if (_options.UseErrorCorrection)
        {
            destination[index++] = ErrorCorrection.ComputeLrc(encodedData);
        }

        destination[index++] = _options.EndByte;
        return index;
    }

    /// <summary>
    /// Converts the supplied bytes to an uppercase hexadecimal string with a single space between each byte.
    /// </summary>
    /// <param name="bytes">The bytes to convert.</param>
    /// <returns>The space separated hexadecimal representation of <paramref name="bytes"/>.</returns>
    private static string FormatHex(ReadOnlySpan<byte> bytes)
    {
        const string hexDigits = "0123456789ABCDEF";
        StringBuilder builder = new(bytes.Length * 3);

        for (int i = 0; i < bytes.Length; i++)
        {
            if (i > 0)
            {
                builder.Append(' ');
            }

            byte value = bytes[i];
            builder.Append(hexDigits[value >> 4]);
            builder.Append(hexDigits[value & 0x0F]);
        }

        return builder.ToString();
    }
}
