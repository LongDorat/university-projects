package practical_session_04.ex2;

import java.util.Scanner;

public class ITStudent extends Student {
    private static final long serialVersionUID = 1L;

    private String username;
    private String password;
    private String email;

    public ITStudent()
    {
        super();
        username = "unknown";
        password = "unknown";
        email = "unknown";
    }

    public ITStudent(String id, String name, Date birthday, int num_course, String[] courseName, String[] courseGrade, String username, String password, String email)
    {
        super(id, name, birthday, num_course, courseName, courseGrade);
        this.username = username;
        this.password = password;
        this.email = email;
    }

    public ITStudent(ITStudent itStudent)
    {
        super(itStudent);
        this.username = itStudent.username;
        this.password = itStudent.password;
        this.email = itStudent.email;
    }

    public void input(Scanner sc){
        super.input(sc);
        System.out.printf("Please type in the username: ");
        username = sc.nextLine();
        System.out.printf("Please type in the password: ");
        password = sc.nextLine();
        System.out.printf("Please type in the email: ");
        email = sc.nextLine();
    }

    public String toString(){
        StringBuilder sb = new StringBuilder();
        sb.append(super.toString());
        sb.append(String.format("Username: %s\n", username));
        sb.append(String.format("Email: %s\n", email));
        return sb.toString();
    }

    public void changePassword(String newPassword){
        password = newPassword;
    }

    public String getEmail() {
        return email;
    }
}
