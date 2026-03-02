package practical_session_04.ex2;

import java.io.FileOutputStream;
import java.io.ObjectOutputStream;
import java.util.Scanner;

public class UserITStudent {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        System.out.printf("Please type in the number of IT students: ");
        n = Integer.parseInt(sc.nextLine());

        ITStudent[] ds = new ITStudent[n];
        for (int i = 0; i < n; i++) {
            ds[i] = new ITStudent();
            ds[i].input(sc);
            ds[i].inputGrade(sc);
        }
        for (int i = 0; i < n; i++) {
            System.out.println(ds[i].toString());
        }

        // Write student object to file
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("sv.ser"))) {
            oos.writeObject(ds);
            System.out.println("\nSuccessfully saved " + n + " students to sv.ser");
        } catch (java.io.IOException e) {
            System.out.println("An error occurred while writing to file: " + e.getMessage());
        }

        // Read the student object from file
        ITStudent[] ds1 = null;
        try (java.io.ObjectInputStream ois = new java.io.ObjectInputStream(new java.io.FileInputStream("sv.ser"))) {
            ds1 = (ITStudent[]) ois.readObject();
            System.out.println("\nStudents read from file:");
            for (ITStudent student : ds1) {
                System.out.println(student.toString());
            }
        } catch (java.io.IOException | ClassNotFoundException e) {
            System.out.println("An error occurred while reading from file: " + e.getMessage());
        }

        // Find student base on email
        System.out.printf("\nPlease type in the email to search for: ");
        String emailToSearch = sc.nextLine();
        boolean found = false;
        for (ITStudent student : ds1) {
            if (student.getEmail().equalsIgnoreCase(emailToSearch)) {
                System.out.println("Student found:");
                student.results();
                found = true;
                break;
            }
        }
        if (!found) {
            System.out.println("Student with email " + emailToSearch + " not found.");
        }

        // Sort ds1 in decending order by average grade
        java.util.Arrays.sort(ds1, (s1, s2) -> Double.compare(s2.avgGrade(), s1.avgGrade()));
        System.out.println("\nStudents sorted by average grade (descending):");
        for (ITStudent student : ds1) {
            System.out.println(student.toString());
        }
    }
}
