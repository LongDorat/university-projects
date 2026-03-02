package practical_session_03_extend.ex2_3;

import java.util.Scanner;

public class Course {
    private String ID;
    private String name;
    private int credits;
    private double grade;

    public Course() {
        ID = null;
        name = null;
        credits = 0;
        grade = 0.0;
    }

    public Course(String ID, String name, int credits, double grade) {
        this.ID = ID;
        this.name = name;
        this.credits = credits;
        this.grade = grade;
    }

    public Course(Course other) {
        this.ID = other.ID;
        this.name = other.name;
        this.credits = other.credits;
        this.grade = other.grade;
    }

    public void input(Scanner sc){
        sc.nextLine(); // Consume the leftover newline

        System.out.print("Enter course ID: ");
        ID = sc.nextLine();
        System.out.print("Enter course name: ");
        name = sc.nextLine();
        System.out.print("Enter number of credits: ");
        credits = sc.nextInt();
        System.out.print("Enter grade: ");
        grade = sc.nextDouble();
    }

    public void display(){
        System.out.printf("%s (%s), %d credits, grade: %.2f\n", name, ID, credits, grade);
    }

    public double convertToFourScale() {
        if (grade >= 9.0)
            return 4.0;
        else if (grade >= 8.0)
            return 3.5;
        else if (grade >= 7.0)
            return 3.0;
        else if (grade >= 6.5)
            return 2.5;
        else if (grade >= 5.5)
            return 2.0;
        else if (grade >= 5.0)
            return 1.5;
        else if (grade >= 4.0)
            return 1.0;
        else
            return 0.0;
    }

    public boolean isPassed() {
        return grade >= 4.0;
    }

    // Getters
    public int getCredits() {
        return credits;
    }
}
