package practical_session_02.ex1;

import java.util.Scanner;

public class UsePoint {
    private static void displayPoint(Point point, String message) {
        System.out.print(message);
        point.display();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Point A = new Point(3, 4);
        displayPoint(A, "A: ");

        Point B = new Point();
        B.input(sc);
        displayPoint(B, "B: ");

        Point C = new Point(-B.getX(), -B.getY());
        displayPoint(C, "C: ");

        System.out.println("The distance between B and O: " + B.distance());
        System.out.println("The distance between A and B: " + A.distance(B));

        sc.close();
    }
}
