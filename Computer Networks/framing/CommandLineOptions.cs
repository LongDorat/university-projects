namespace Framing;

/// <summary>
/// Holds the validated values parsed from the command line.
/// </summary>
internal sealed record CommandLineOptions
{
    /// <summary>
    /// Gets the path of the file that is streamed into frames.
    /// </summary>
    public required string InputPath { get; init; }

    /// <summary>
    /// Gets the number of data bytes per frame.
    /// </summary>
    public required int FrameSize { get; init; }

    /// <summary>
    /// Gets the frame start marker.
    /// </summary>
    public required byte StartByte { get; init; }

    /// <summary>
    /// Gets the frame end marker.
    /// </summary>
    public required byte EndByte { get; init; }

    /// <summary>
    /// Gets a value indicating whether VRC and LRC error correction is enabled.
    /// </summary>
    public bool UseErrorCorrection { get; init; }
}
