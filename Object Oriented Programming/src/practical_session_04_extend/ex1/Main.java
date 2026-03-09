package practical_session_04_extend.ex1;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n;
        System.out.print("Enter number of courses: ");
        n = Integer.parseInt(sc.nextLine());

        UniversityCourse[] courses = new UniversityCourse[n];
        for (int i = 0; i < n; i++) {
            System.out.printf("Course %d:\n", i + 1);
            courses[i] = new UniversityCourse();
            courses[i].input(sc);
        }

        for (UniversityCourse course : courses) {
            int numberOfStudents;
            System.out.printf("Enter number of students to register for course %s: ", course.getName());
            numberOfStudents = Integer.parseInt(sc.nextLine());

            for (int j = 0; j < numberOfStudents; j++) {
                System.out.printf("Enter name of student %d: ", j + 1);
                String studentName = sc.nextLine();
                course.RegisterStudent(studentName);
            }
        }

        for (int i = 0; i < n; i++) {
            System.out.printf("Course %d details:\n", i + 1);
            courses[i].display();
        }

        System.out.printf("Course with the most students: \n");
        int maxEnrolled = 0;
        UniversityCourse courseWithMostStudents = null;
        for (UniversityCourse course : courses) {
            if (course.getNumStudents() > maxEnrolled) {
                maxEnrolled = course.getNumStudents();
                courseWithMostStudents = course;
            }
        }
        if (courseWithMostStudents != null) {
            System.out.printf("Name: %s, Enrolled Students: %d\n", courseWithMostStudents.getName(), maxEnrolled);
        }else {
            System.out.println("No courses found.");
        }

        Arrays.sort(courses, Comparator.comparingInt(UniversityCourse::getNumStudents).reversed());
        System.out.println("Courses sorted by number of students (descending):");
        for (UniversityCourse course : courses) {
            System.out.printf("Name: %s, Enrolled Students: %d\n", course.getName(), course.getNumStudents());
        }

    }
}
