package practical_session_03.ex1;

import java.util.Scanner;

public class Tile {
    private String code;
    private String color;
    private int numOfTile;
    private int length;
    private int width;
    private long price;

    public Tile() {
        code = null;
        color = null;
        numOfTile = 0;
        length = 0;
        width = 0;
        price = 0;
    }

    public Tile(String code, String color, int numOfTile, int length, int width, int price) {
        this.code = code;
        this.color = color;
        this.numOfTile = numOfTile;
        this.length = length;
        this.width = width;
        this.price = price;
    }

    public Tile(Tile tile) {
        this.code = tile.code;
        this.color = tile.color;
        this.numOfTile = tile.numOfTile;
        this.length = tile.length;
        this.width = tile.width;
        this.price = tile.price;
    }

    public void input(Scanner scanner) {
        code = readValidString(scanner, "Tile's code: ");
        color = readValidString(scanner, "Tile's color: ");
        numOfTile = readValidInt(scanner, "Number of Tile inside one box: ", 1);
        length = readValidInt(scanner, "Length of one Tile: ", 1);
        width = readValidInt(scanner, "Width of one Tile: ", 1);
        price = readValidLong(scanner, "Price of one box: ", 0);

        scanner.nextLine(); // Clear the buffer
    }

    public void display() {
        System.out.printf("Tile's code: %s\n", code);
        System.out.printf("Tile's color: %s\n", color);
        System.out.printf("Number of Tile in one box: %d\n", numOfTile);
        System.out.printf("Length: %d\t Width: %d\n", length, width);
        System.out.printf("Price (each box): %,d\n", price);
    }

    public float retailPrice() {
        return (float) ((float) price / numOfTile * 1.2);
    }

    public float maxArea() {
        int tileArea = length * width;
        return (float) tileArea * numOfTile;
    }

    public int numTile(int L, int W) {
        int requiredArea = L * W;
        int tileArea = length * width;
        return (int) Math.ceil((double) requiredArea / tileArea);
    }

    // ? Helpers
    public String getCode() {
        return code;
    }

    public long getPrice() {
        return price;
    }

    public int getNumOfTile() {
        return numOfTile;
    }

    private String readValidString(Scanner scanner, String prompt) {
        String input;
        do {
            System.out.printf(prompt);
            input = scanner.nextLine().trim();
            if (input.isEmpty()) {
                System.out.println("Error: Input cannot be empty. Please try again.");
            }
        } while (input.isEmpty());
        return input;
    }

    private int readValidInt(Scanner scanner, String prompt, int minValue) {
        int value;
        do {
            System.out.printf(prompt);
            while (!scanner.hasNextInt()) {
                System.out.println("Error: Please enter a valid integer.");
                scanner.next(); // Clear invalid input
                System.out.printf(prompt);
            }
            value = scanner.nextInt();
            if (value < minValue) {
                System.out.printf("Error: Value must be at least %d. Please try again.%n", minValue);
            }
        } while (value < minValue);
        return value;
    }

    private long readValidLong(Scanner scanner, String prompt, long minValue) {
        long value;
        do {
            System.out.printf(prompt);
            while (!scanner.hasNextLong()) {
                System.out.println("Error: Please enter a valid number.");
                scanner.next(); // Clear invalid input
                System.out.printf(prompt);
            }
            value = scanner.nextLong();
            if (value < minValue) {
                System.out.printf("Error: Value must be at least %d. Please try again.%n", minValue);
            }
        } while (value < minValue);
        return value;
    }
}
