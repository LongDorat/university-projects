package practical_session_04_extend.ex1;

public class UniversityCourse extends Course {
    private String teacherName;
    private String classRoom;
    private String[] listStudents;
    private int numStudents;

    public UniversityCourse() {
        super();
        teacherName = null;
        classRoom = null;
        listStudents = new String[0];
        numStudents = 0;
    }

    public UniversityCourse(String ID, String name, int credits, double grade, String teacherName, String classRoom) {
        super(ID, name, credits, grade);
        this.teacherName = teacherName;
        this.classRoom = classRoom;
        listStudents = new String[0];
        numStudents = 0;
    }

    public void display(){
        super.display();
        System.out.printf("Teacher: %s, Classroom: %s\n", teacherName, classRoom);
        System.out.println("Enrolled students:");
        for (int i = 0; i < numStudents; i++) {
            System.out.printf("\t- %s\n", listStudents[i]);
        }
    }

    public void input(java.util.Scanner sc) {
        super.input(sc);
        System.out.print("Enter teacher name: ");
        teacherName = sc.nextLine();
        System.out.print("Enter classroom: ");
        classRoom = sc.nextLine();
    }

    public void RegisterStudent(String studentName) {
        if (numStudents < listStudents.length) {
            listStudents[numStudents++] = studentName;
        } else {
            String[] newList = new String[listStudents.length + 10];
            System.arraycopy(listStudents, 0, newList, 0, listStudents.length);
            listStudents = newList;
            listStudents[numStudents++] = studentName;
        }
    }

    public void RemoveStudent(String studentName) {
        for (int i = 0; i < numStudents; i++) {
            if (listStudents[i].equals(studentName)) {
                for (int j = i; j < numStudents - 1; j++) {
                    listStudents[j] = listStudents[j + 1];
                }
                listStudents[--numStudents] = null;
                break;
            }
        }
    }

    public boolean isStudentEnrolled(String studentName) {
        for (int i = 0; i < numStudents; i++) {
            if (listStudents[i].equals(studentName)) {
                return true;
            }
        }
        return false;
    }

    public int getNumStudents() {
        return numStudents;
    }

    public String getName() {
        return super.getName();
    }
}
