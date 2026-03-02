package practical_session_04.ex2;

import java.io.Serializable;

public class Student implements Serializable {
    private static final long serialVersionUID = 1L;

    private String id;
    private String name;
    private Date birthday;
    private int num_course;
    private String[] courseName;
    private String[] courseGrade;

    public Student() {
        id = null;
        name = null;
        birthday = new Date();
        num_course = 0;
        courseName = null;
        courseGrade = null;
    }

    public Student(String id, String name, Date birthday, int num_course, String[] courseName, String[] courseGrade) {
        this.id = id;
        this.name = name;
        this.birthday = birthday;
        this.num_course = num_course;
        this.courseName = courseName;
        this.courseGrade = courseGrade;
    }

    public Student(Student student) {
        this.id = student.id;
        this.name = student.name;
        this.birthday = student.birthday;
        this.num_course = student.num_course;
        this.courseName = student.courseName;
        this.courseGrade = student.courseGrade;
    }

    public void input(java.util.Scanner scanner){
        id = readValidString(scanner, "Student ID: ", 1, false);
        name = readValidString(scanner, "Student Name: ", 1, true);
        System.out.println("Enter Birthday: ");
        birthday.input(scanner);
    }

    public void inputGrade(java.util.Scanner scanner){
        num_course = readValidInt(scanner, "Number of courses: ", 1);
        courseName = new String[num_course];
        courseGrade = new String[num_course];

        for (int i = 0; i < num_course; i++) {
            courseName[i] = readValidString(scanner, String.format("Course %d name: ", i + 1), 1, true);
            courseGrade[i] = readValidString(scanner, String.format("Course %d grade: ", i + 1), 1, false);
        }
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(String.format("Student ID: %s\n", id));
        sb.append(String.format("Student Name: %s\n", name));
        sb.append("Birthday: ");
        sb.append(String.format("%d/%d/%d\n", birthday.getDay(), birthday.getMonth(), birthday.getYear()));
        sb.append(String.format("Number of courses: %d\n", num_course));
        for (int i = 0; i < num_course; i++) {
            sb.append(String.format("Course %d: %s - Grade: %s\n", i + 1, courseName[i], courseGrade[i]));
        }
        sb.append(String.format("Average Grade: %.2f\n", avgGrade()));
        return sb.toString();
    }

    // On scale of 4.0
    public float avgGrade(){
        float total = 0;
        for (int i = 0; i < num_course; i++) {
            switch (courseGrade[i].toUpperCase()) {
                case "A":
                    total += 4.0;
                    break;
                case "B+":
                    total += 3.5;
                    break;
                case "B":
                    total += 3.0;
                    break;
                case "C+":
                    total += 2.5;
                    break;
                case "C":
                    total += 2.0;
                    break;
                case "D+":
                    total += 1.5;
                    break;
                case "D":
                    total += 1.0;
                    break;
                case "F":
                    total += 0.0;
                    break;
                default:
                    System.out.printf("Invalid grade '%s' for course '%s'. Assuming 0.0 points.\n", courseGrade[i], courseName[i]);
                    total += 0.0;
                    break;
            }
        }
        return total / num_course;
    }

    public void  addCourse(java.util.Scanner scanner){
        String newCourseName = readValidString(scanner, "New course name: ", 1, true);
        String newCourseGrade = readValidString(scanner, "New course grade: ", 1, false);

        String[] updatedCourseNames = new String[num_course + 1];
        String[] updatedCourseGrades = new String[num_course + 1];

        for (int i = 0; i < num_course; i++) {
            updatedCourseNames[i] = courseName[i];
            updatedCourseGrades[i] = courseGrade[i];
        }

        updatedCourseNames[num_course] = newCourseName;
        updatedCourseGrades[num_course] = newCourseGrade;

        courseName = updatedCourseNames;
        courseGrade = updatedCourseGrades;
        num_course++;
    }

    public void deleteCourse(String name){
        int index = -1;
        for (int i = 0; i < num_course; i++) {
            if (courseName[i].equalsIgnoreCase(name)) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            System.out.printf("Course '%s' not found.\n", name);
            return;
        }

        String[] updatedCourseNames = new String[num_course - 1];
        String[] updatedCourseGrades = new String[num_course - 1];

        for (int i = 0, j = 0; i < num_course; i++) {
            if (i != index) {
                updatedCourseNames[j] = courseName[i];
                updatedCourseGrades[j] = courseGrade[i];
                j++;
            }
        }

        courseName = updatedCourseNames;
        courseGrade = updatedCourseGrades;
        num_course--;
    }

    public void results(){
        System.out.printf("Student ID: %s - Name: %s\n", id, name);
        System.out.printf("Average Grade: %.2f\n", avgGrade());
        System.out.println("Courses:");
        for (int i = 0; i < num_course; i++) {
            System.out.printf("  %s: %s\n", courseName[i], courseGrade[i]);
        }
    }

    //? Getters
    public String getName() {
        return name;
    }

    //? Helper
    public boolean isAcademicWarning(){
        return avgGrade() <= 1.0;
    }

    private String readValidString(java.util.Scanner scanner, String prompt, int minLength, boolean isSpacing){
        String input;
        do {
            System.out.print(prompt);
            input = scanner.nextLine();

            if (!isSpacing) {
                input = input.trim();
            }

            if (input.length() < minLength) {
                System.out.printf("Input must be at least %d characters long. Please try again.\n", minLength);
            }
        } while (input.length() < minLength);

        return input;
    }   

    private int readValidInt(java.util.Scanner scanner, String prompt, int minValue){
        int value;
        while (true) {
            System.out.print(prompt);
            try {
                value = Integer.parseInt(scanner.nextLine());
                if (value < minValue) {
                    System.out.printf("Input must be at least %d. Please try again.\n", minValue);
                } else {
                    break;
                }
            } catch (NumberFormatException e) {
                System.out.println("Invalid input. Please enter a valid integer.");
            }
        }
        return value;
    }
}
