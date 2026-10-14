using System.Numerics;

namespace Framing;

/// <summary>
/// Provides the VRC and LRC error correction primitives used while framing data.
/// </summary>
public static class ErrorCorrection
{
    /// <summary>
    /// Adds an even-parity VRC bit to the most significant bit of a 7-bit ASCII value.
    /// </summary>
    /// <param name="value">The raw 7-bit ASCII value. Only the lower seven bits are used.</param>
    /// <returns>The value with the VRC bit stored in the most significant bit.</returns>
    public static byte AddVrc(byte value)
    {
        byte data = (byte)(value & 0x7F);
        int parity = BitOperations.PopCount(data) & 1;
        return (byte)(data | (parity << 7));
    }

    /// <summary>
    /// Computes the longitudinal redundancy check (LRC) over a sequence of VRC encoded bytes.
    /// </summary>
    /// <remarks>
    /// The LRC is the XOR of the supplied bytes. Because every byte already carries its VRC bit,
    /// the most significant bit of the returned LRC is the VRC bit for the LRC byte itself.
    /// </remarks>
    /// <param name="encodedData">The data bytes that already contain their VRC bit.</param>
    /// <returns>The LRC byte.</returns>
    public static byte ComputeLrc(ReadOnlySpan<byte> encodedData)
    {
        byte lrc = 0;
        foreach (byte value in encodedData)
        {
            lrc ^= value;
        }

        return lrc;
    }
}
