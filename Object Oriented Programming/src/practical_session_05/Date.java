package practical_session_05;

public class Date {
    int day;
    int month;
    int year;

    public boolean isTheDate(int day, int month, int year) {
        return this.day == day && this.month == month && this.year == year;
    }

    public void inputDate(java.util.Scanner scanner) {
        System.out.print("Enter day: ");
        day = Integer.parseInt(scanner.nextLine());
        System.out.print("Enter month: ");
        month = Integer.parseInt(scanner.nextLine());
        System.out.print("Enter year: ");
        year = Integer.parseInt(scanner.nextLine());
    }

    public void displayDate() {
        System.out.println(day + "/" + month + "/" + year);
    }
}
