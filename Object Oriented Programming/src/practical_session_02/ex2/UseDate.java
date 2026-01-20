package practical_session_02.ex2;

public class UseDate {
    public static void main(String[] args) {
        // Test 1: Create a date using constructor
        System.out.println("=== Test 1: Constructor ===");
        Date date1 = new Date(28, 2, 2024);
        date1.display();
        System.out.println("Valid: " + date1.isValidDate());

        // Test 2: Next date (leap year)
        System.out.println("\n=== Test 2: Next Date (Leap Year) ===");
        Date nextDay = date1.nextDate();
        nextDay.display();

        // Test 3: Year transition
        System.out.println("\n=== Test 3: Year Transition ===");
        Date endYear = new Date(31, 12, 2023);
        endYear.display();
        Date newYear = endYear.nextDate();
        newYear.display();

        // Test 4: Add days
        System.out.println("\n=== Test 4: Add 10 Days ===");
        Date start = new Date(25, 1, 2024);
        start.display();
        Date future = start.add(10);
        future.display();

        // Test 5: Invalid date
        System.out.println("\n=== Test 5: Invalid Date ===");
        Date invalid = new Date(31, 4, 2024);
        invalid.display();
        System.out.println("Valid: " + invalid.isValidDate());

        // Test 6: User input
        // System.out.println("\n=== Test 6: User Input ===");
        // Date userDate = new Date();
        // userDate.input();
        // userDate.display();
    }
}
