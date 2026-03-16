package practical_session_03.ex2;

public class LineSegment {
    private Point d1;
    private Point d2;

    public LineSegment() {
        d1 = new Point();
        d2 = new Point();
    }

    public LineSegment(Point d1, Point d2) {
        this.d1 = d1;
        this.d2 = d2;
    }

    public LineSegment(int x1, int y1, int x2, int y2) {
        this.d1 = new Point(x1, y1);
        this.d2 = new Point(x2, y2);
    }

    public void input(java.util.Scanner scanner) {
        System.out.println("Input for point 1:");
        d1.input(scanner);
        System.out.println("Input for point 2:");
        d2.input(scanner);
    }

    public void display() {
        System.out.print("Point 1: ");
        d1.display();
        System.out.print("Point 2: ");
        d2.display();
    }

    public void move(int dx, int dy) {
        d1.move(dx, dy);
        d2.move(dx, dy);
    }

    public float length() {
        return d1.distance(d2);
    }
}
