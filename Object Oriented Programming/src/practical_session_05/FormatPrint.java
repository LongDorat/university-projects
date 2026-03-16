package practical_session_05;

public class FormatPrint {
    public static void printBanner(String message) {
        int length = message.length();
        String border = "*".repeat(length + 4);
        System.out.println(border);
        System.out.println("* " + message + " *");
        System.out.println(border);
    }

    public static void printLeftRightAligned(String left, String right, int width) {
        if (left.length() + right.length() + 1 > width) {
            System.out.println("Error: The combined length of left and right exceeds the specified width.");
            return;
        }
        String formatted = String.format("%-" + (width - right.length()) + "s%s", left, right);
        System.out.println(formatted);
    }
}
