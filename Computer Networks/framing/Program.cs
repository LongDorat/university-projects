using System.Text;

namespace Framing;

/// <summary>
/// Contains the entry point for the framing console application.
/// </summary>
internal static class Program
{
    /// <summary>
    /// Parses the command line arguments and streams the input file into frames on standard output.
    /// </summary>
    /// <param name="args">The raw command line arguments.</param>
    /// <returns>Zero on success; otherwise a non-zero exit code.</returns>
    private static async Task<int> Main(string[] args)
    {
        if (args.Length == 0)
        {
            PrintUsage(Console.Error);
            return 1;
        }

        if (args.Contains("--help") || args.Contains("-h"))
        {
            PrintUsage(Console.Out);
            return 0;
        }

        if (!CommandLineParser.TryParse(args, out CommandLineOptions? parsed, out string? error))
        {
            await Console.Error.WriteLineAsync(error).ConfigureAwait(false);
            PrintUsage(Console.Error);
            return 1;
        }

        FrameOptions options = new()
        {
            FrameSize = parsed.FrameSize,
            StartByte = parsed.StartByte,
            EndByte = parsed.EndByte,
            UseErrorCorrection = parsed.UseErrorCorrection,
        };

        try
        {
            await using FileStream input = new(
                parsed.InputPath,
                FileMode.Open,
                FileAccess.Read,
                FileShare.Read,
                bufferSize: 4096,
                FileOptions.Asynchronous | FileOptions.SequentialScan);

            await using StreamWriter output = new(
                Console.OpenStandardOutput(),
                new UTF8Encoding(encoderShouldEmitUTF8Identifier: false))
            {
                AutoFlush = false,
            };

            FrameEncoder encoder = new(options);
            await encoder.EncodeAsync(input, output).ConfigureAwait(false);
            await output.FlushAsync().ConfigureAwait(false);
        }
        catch (FileNotFoundException)
        {
            await Console.Error.WriteLineAsync($"Input file '{parsed.InputPath}' was not found.").ConfigureAwait(false);
            return 1;
        }
        catch (IOException exception)
        {
            await Console.Error.WriteLineAsync($"Failed to read '{parsed.InputPath}': {exception.Message}").ConfigureAwait(false);
            return 1;
        }

        return 0;
    }

    /// <summary>
    /// Writes the command line usage text to the supplied writer.
    /// </summary>
    /// <param name="writer">The writer that receives the usage text.</param>
    private static void PrintUsage(TextWriter writer)
    {
        writer.WriteLine("Usage: framing <inputFile> <frameSize> <startByte> <endByte> [--ecc]");
        writer.WriteLine();
        writer.WriteLine("  inputFile   Path to the file that is streamed into frames.");
        writer.WriteLine("  frameSize   Number of data bytes per frame (start, end and LRC bytes excluded).");
        writer.WriteLine("  startByte   Frame start marker. Accepts decimal (126) or hexadecimal (0x7E).");
        writer.WriteLine("  endByte     Frame end marker. Accepts decimal (126) or hexadecimal (0x7E).");
        writer.WriteLine("  --ecc, -e   Adds VRC to every data byte and an LRC byte to every frame.");
        writer.WriteLine();
        writer.WriteLine("Each frame is written to standard output as an upper case hexadecimal string,");
        writer.WriteLine("followed by a newline. The final frame may be shorter than frameSize.");
        writer.WriteLine();
        writer.WriteLine("Example: framing data.txt 5 0x7E 0x7E --ecc");
    }
}
