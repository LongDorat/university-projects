namespace Framing;

/// <summary>
/// Describes how a stream is split into frames.
/// </summary>
public sealed record FrameOptions
{
    /// <summary>
    /// Gets the number of data bytes carried by each frame. This value excludes the start byte,
    /// the end byte and the optional LRC byte.
    /// </summary>
    public required int FrameSize { get; init; }

    /// <summary>
    /// Gets the byte that marks the beginning of a frame.
    /// </summary>
    public required byte StartByte { get; init; }

    /// <summary>
    /// Gets the byte that marks the end of a frame.
    /// </summary>
    public required byte EndByte { get; init; }

    /// <summary>
    /// Gets a value indicating whether VRC and LRC error correction is added to each frame.
    /// </summary>
    public bool UseErrorCorrection { get; init; }
}
