package practical_session_03.ex3;

import java.util.ArrayList;

public class UseStudent {
    public static void main(String[] args) {
        java.util.Scanner scanner = new java.util.Scanner(System.in);

        Student a = new Student();
        a.input(scanner);
        scanner.nextLine();
        a.inputGrade(scanner);

        a.addCourse(scanner);
        scanner.nextLine();

        System.out.println(a.toString());
        System.out.println();

        System.out.print("Enter number of students: ");
        int n = scanner.nextInt();
        scanner.nextLine();

        Student[] list = new Student[n];
        ArrayList<Student> academicWarningStudents = new ArrayList<>();
        ArrayList<Student> highestAverageList = new ArrayList<>();
        double highestAverage = -1;
        for (int i = 0; i < n; i++) {
            System.out.printf("Enter information for student %d:\n", i + 1);
            list[i] = new Student();
            list[i].input(scanner);
            scanner.nextLine();
            list[i].inputGrade(scanner);

            if (list[i].isAcademicWarning()) {
                academicWarningStudents.add(list[i]);
            }

            double avg = list[i].avgGrade();
            if (avg > highestAverage) {
                highestAverage = avg;
                highestAverageList.clear();
                highestAverageList.add(list[i]);
            } else if (avg == highestAverage) {
                highestAverageList.add(list[i]);
            }
        }

        System.out.println("===List of students===");
        for (int i = 0; i < n; i++) {
            System.out.println(list[i].toString());
        }

        System.out.println("===Students on academic warning===");
        for (Student s : academicWarningStudents) {
            System.out.println(s.toString());
        }

        System.out.println("===Students with the highest average grade===");
        for (Student s : highestAverageList) {
            System.out.println(s.toString());
        }

        System.out.println("===List in alphabetical order of Name===");
        java.util.Arrays.sort(list, (s1, s2) -> s1.getName().compareToIgnoreCase(s2.getName()));
        for (int i = 0; i < n; i++) {
            System.out.println(list[i].toString());
        }

        scanner.close();
    }
}
