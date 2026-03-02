package practical_session_04.ex1;

import java.util.Scanner;

public class UseColorPoint {
    public static void main(String[] args) {
        ColorPoint colorA = new ColorPoint(5, 10, "white");
        colorA.display();
        System.out.println();

        Scanner sc = new Scanner(System.in);
        ColorPoint colorB = new ColorPoint();
        colorB.input(sc);
        colorB.move(2, 2);
        colorB.changeColor("Yellow");
        colorB.display();
    }
}
