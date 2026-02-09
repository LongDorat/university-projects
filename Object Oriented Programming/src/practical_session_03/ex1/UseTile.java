package practical_session_03.ex1;

import java.util.Scanner;

public class UseTile {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n;
        System.out.printf("Number of Type: ");
        n = scanner.nextInt();
        scanner.nextLine();
        System.out.println();

        Tile List[] = new Tile[n];
        Tile MostEfficientTile = new Tile();
        for (int i = 0; i < n; i++) {
            List[i] = new Tile();
            System.out.printf("Input information for Tile %d:\n", i + 1);
            List[i].input(scanner);
            System.out.println();

            double currentEfficient = List[i].getPrice() / List[i].maxArea();
            if (i == 0) {
                MostEfficientTile = new Tile(List[i]);
            } else {
                double mostEfficient = MostEfficientTile.getPrice() / MostEfficientTile.maxArea();
                if (currentEfficient < mostEfficient) {
                    MostEfficientTile = new Tile(List[i]);
                }
            }
        }

        System.out.println("The most efficient tile is: ");
        MostEfficientTile.display();
        System.out.println();

        final int width = 500;
        final int length = 1500;
        for (int i = 0; i < n; i++) {
            int requiedTile = List[i].numTile(length, width);
            int requiredBox = (int) Math.ceil((double) requiedTile / List[i].getNumOfTile());
            long totalPrice = requiredBox * List[i].getPrice();

            System.out.printf("Tile %s requires %d tiles, %d boxes, with total price: %,d\n",
                    List[i].getCode(), requiedTile, requiredBox, totalPrice);
        }

    }
}
