package practical_session_03_custom.ex2_3;

import java.util.Scanner;

public class Student {
    private String ID;
    private String name;
    private Course[] courses;
    private int courseCount;

    public Student() {
        ID = null;
        name = null;
        courses = new Course[10];
        courseCount = 0;
    }

    public Student(String ID, String name, int courseCount) {
        this.ID = ID;
        this.name = name;
        courses = new Course[courseCount];
        this.courseCount = courseCount;
    }

    public Student(Student other) {
        this.ID = other.ID;
        this.name = other.name;
        this.courseCount = other.courseCount;
        this.courses = new Course[courseCount];
        for (int i = 0; i < courseCount; i++) {
            this.courses[i] = new Course(other.courses[i]);
        }
    }

    public void input(Scanner sc) {
        sc.nextLine(); // Consume the leftover newline

        System.out.print("Enter student ID: ");
        ID = sc.nextLine();
        System.out.print("Enter student name: ");
        name = sc.nextLine();
        System.out.print("Enter number of courses: ");
        courseCount = sc.nextInt();
        courses = new Course[courseCount];
        for (int i = 0; i < courseCount; i++) {
            System.out.println("Course " + (i + 1) + ":");
            courses[i] = new Course();
            courses[i].input(sc);
        }
    }

    public void display(){
        System.out.printf("Student: %s (%s), GPA: %.2f\n", name, ID, calculateGPA());
        for (int i = 0; i < courseCount; i++) {
            System.out.printf("\tCourse %d: ", i + 1);
            courses[i].display();
        }
    }

    public double calculateGPA() {
        double totalPoints = 0.0;
        int totalCredits = 0;
        for (int i = 0; i < courseCount; i++) {
            totalPoints += courses[i].convertToFourScale() * courses[i].getCredits();
            totalCredits += courses[i].getCredits();
        }
        return totalCredits > 0 ? totalPoints / totalCredits : 0.0;
    }

    public int countPassedCourses() {
        int count = 0;
        for (int i = 0; i < courseCount; i++) {
            if (courses[i].isPassed()) {
                count++;
            }
        }
        return count;
    }
}
