package practical_session_02.ex2;

import java.util.Scanner;

public class Date {
    private static Scanner sc = new Scanner(System.in);
    private int day, month, year;

    public Date() {    }

    public Date(int day, int month, int year) {
        this.day = day;
        this.month = month;
        this.year = year;
    }

    public void display() {
        System.out.printf("Date is: %d/%d/%d\n", day, month, year);
    }

    private boolean leapYear() {
        if (year % 4 == 0) {
            if (year % 100 == 0)
                return year % 400 == 0;

            return true;
        }

        return false;
    }

    public boolean isValidDate() {
        if (month < 1 || month > 12)
            return false;

        int leapDay = leapYear() ? 29 : 28;

        switch (month) {
            case 1, 3, 5, 7, 8, 10, 12 -> {
                if (day < 1 || day > 31)
                    return false;
            }
            case 4, 6, 9, 11 -> {
                if (day < 1 || day > 30)
                    return false;
            }
            case 2 -> {
                if (day < 1 || day > leapDay)
                    return false;
            }
        }
        return true;
    }

    public void input() {
        do {
            System.out.printf("Please type in the day: ");
            day = sc.nextInt();

            System.out.printf("Please type in the month: ");
            month = sc.nextInt();

            System.out.printf("Please type in the year: ");
            year = sc.nextInt();

            if (isValidDate()) {
                break;
            }
            System.out.printf("The date is invalid! Please retype!\n");
        } while (true);
    }

    private int getDaysInMonth(int month) {
        return switch (month) {
            case 1, 3, 5, 7, 8, 10, 12 -> 31;
            case 4, 6, 9, 11 -> 30;
            case 2 -> leapYear() ? 29 : 28;
            default -> 0;
        };
    }

    public Date nextDate() {
        int nextDay = day;
        int nextMonth = month;
        int nextYear = year;

        int daysInMonth = getDaysInMonth(this.month);

        if (day < daysInMonth) {
            nextDay++;
        } else {
            nextDay = 1;
            if (month < 12) {
                nextMonth++;
            } else {
                nextMonth = 1;
                nextYear++;
            }
        }

        return new Date(nextDay, nextMonth, nextYear);
    }

    public Date add(int n) {
        Date result = new Date(this.day, this.month, this.year);

        for (int i = 0; i < n; i++) {
            result = result.nextDate();
        }

        return result;
    }
}
