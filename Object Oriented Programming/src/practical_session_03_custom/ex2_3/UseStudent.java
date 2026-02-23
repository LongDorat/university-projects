package practical_session_03_custom.ex2_3;

import java.util.ArrayList;
import java.util.Scanner;

public class UseStudent {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n;
        System.out.print("Enter number of students: ");
        n = sc.nextInt();

        Student[] students = new Student[n];
        for (int i = 0; i < n; i++) {
            System.out.println("Student " + (i + 1) + ":");
            students[i] = new Student();
            students[i].input(sc);
            System.out.println();
        }
        

        // Students with highest GPA
        double maxGPA = 0.0;
        ArrayList<Student> topStudents = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            double gpa = students[i].calculateGPA();
            if (gpa > maxGPA) {
                maxGPA = gpa;
                topStudents.clear();
                topStudents.add(students[i]);
            } else if (gpa == maxGPA) {
                topStudents.add(students[i]);
            }
        }
        System.out.println("Highest GPA: " + maxGPA);
        System.out.println("Students with highest GPA:");
        for (Student s : topStudents) {
            s.display();
        }
        System.out.println();

        // Sort students by GPA
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (students[j].calculateGPA() < students[j + 1].calculateGPA()) {
                    Student temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }
        System.out.println("Students sorted by GPA:");
        for (Student s : students) {
            s.display();
        }

        sc.close();
    }
}
