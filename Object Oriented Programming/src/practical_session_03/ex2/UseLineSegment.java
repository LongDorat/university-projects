package practical_session_03.ex2;

import java.util.Scanner;

public class UseLineSegment {
    public static void main (String[] args){
        Point A = new Point(2, 5);
        Point B = new Point(20, 35);
        LineSegment AB = new LineSegment(A, B);
        AB.display();

        Scanner scanner = new Scanner(System.in);
        LineSegment CD = new LineSegment();
        CD.input(scanner);
        CD.display();
    }
}
