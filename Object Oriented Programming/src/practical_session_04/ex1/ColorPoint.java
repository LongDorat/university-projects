package practical_session_04.ex1;

import java.util.Scanner;

public class ColorPoint extends Point{
    private String color;

    public ColorPoint()
    {
        super();
        color = "white";
    }

    public ColorPoint(int x, int y, String color)
    {
        super(x, y);
        this.color = String.valueOf(color);
    }

    public void input(Scanner sc)
    {
        super.input(sc);
        System.out.printf("Please type in the color of the point: ");
        color = sc.next();
    }

    public void display()
    {
        super.display();
        System.out.printf("The color of the point is: %s\n", color);
    }

    public void changeColor(String newColor)
    {
        color = String.valueOf(newColor);
    }
}
