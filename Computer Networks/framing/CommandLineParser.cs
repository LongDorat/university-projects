using System.Diagnostics.CodeAnalysis;
using System.Globalization;

namespace Framing;

/// <summary>
/// Parses the command line arguments for the framing application.
/// </summary>
internal static class CommandLineParser
{
    /// <summary>
    /// Attempts to parse the supplied arguments into a <see cref="CommandLineOptions"/> instance.
    /// </summary>
    /// <param name="args">The raw command line arguments.</param>
    /// <param name="options">When this method returns <see langword="true"/>, contains the parsed options.</param>
    /// <param name="error">When this method returns <see langword="false"/>, contains the reason parsing failed.</param>
    /// <returns><see langword="true"/> when parsing succeeds; otherwise <see langword="false"/>.</returns>
    public static bool TryParse(
        string[] args,
        [NotNullWhen(true)] out CommandLineOptions? options,
        [NotNullWhen(false)] out string? error)
    {
        List<string> positionals = [];
        bool useErrorCorrection = false;

        foreach (string argument in args)
        {
            switch (argument)
            {
                case "--ecc":
                case "-e":
                case "--error-correction":
                    useErrorCorrection = true;
                    break;
                default:
                    if (argument.StartsWith('-'))
                    {
                        options = null;
                        error = $"Unknown option '{argument}'.";
                        return false;
                    }

                    positionals.Add(argument);
                    break;
            }
        }

        if (positionals.Count != 4)
        {
            options = null;
            error = "Expected four positional arguments: <inputFile> <frameSize> <startByte> <endByte>.";
            return false;
        }

        if (!int.TryParse(positionals[1], NumberStyles.Integer, CultureInfo.InvariantCulture, out int frameSize) || frameSize < 1)
        {
            options = null;
            error = $"Frame size '{positionals[1]}' must be a positive integer.";
            return false;
        }

        if (!TryParseByte(positionals[2], out byte startByte))
        {
            options = null;
            error = $"Start byte '{positionals[2]}' must be a byte value such as 126 or 0x7E.";
            return false;
        }

        if (!TryParseByte(positionals[3], out byte endByte))
        {
            options = null;
            error = $"End byte '{positionals[3]}' must be a byte value such as 126 or 0x7E.";
            return false;
        }

        options = new CommandLineOptions
        {
            InputPath = positionals[0],
            FrameSize = frameSize,
            StartByte = startByte,
            EndByte = endByte,
            UseErrorCorrection = useErrorCorrection,
        };
        error = null;
        return true;
    }

    /// <summary>
    /// Parses a single byte value from either decimal or hexadecimal notation.
    /// </summary>
    /// <param name="text">The text to parse, for example <c>126</c> or <c>0x7E</c>.</param>
    /// <param name="value">When this method returns <see langword="true"/>, contains the parsed byte.</param>
    /// <returns><see langword="true"/> when the text represents a valid byte; otherwise <see langword="false"/>.</returns>
    private static bool TryParseByte(string text, out byte value)
    {
        value = 0;

        if (string.IsNullOrWhiteSpace(text))
        {
            return false;
        }

        string trimmed = text.Trim();
        if (trimmed.StartsWith("0x", StringComparison.OrdinalIgnoreCase))
        {
            return byte.TryParse(trimmed[2..], NumberStyles.HexNumber, CultureInfo.InvariantCulture, out value);
        }

        return byte.TryParse(trimmed, NumberStyles.Integer, CultureInfo.InvariantCulture, out value);
    }
}
