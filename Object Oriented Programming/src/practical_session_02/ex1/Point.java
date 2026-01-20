package practical_session_02.ex1;

import java.util.Scanner;

public class Point {
    private static final Scanner sc = new Scanner(System.in);
    private int x, y;

    public Point() {
        x = 0;
        y = 0;
    }

    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public void input() {
        System.out.printf("Please type in the number for x: ");
        x = sc.nextInt();

        System.out.printf("Please type in the number for y: ");
        y = sc.nextInt();
    }

    public void display() {
        System.out.printf("(%d, %d)\n", x, y);
    }

    public void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    public int getX() {
        return x;
    }

    public int getY() {
        return y;
    }

    public float distance() {
        return (float) Math.sqrt(Math.pow(x, 2) + Math.pow(y, 2));
    }

    public float distance(Point d) {
        return (float) Math.sqrt(Math.pow(d.getX() - x, 2) + Math.pow(d.getY() - y, 2));
    }
}