package practical_session_04_extend.ex2;

public class Car extends Vehicle {
    public static int carCount = 0;
    private int numberOfSeats;

    public Car() {
        super();
        numberOfSeats = 0;
        carCount++;
    }

    @Override
    public void input(java.util.Scanner sc) {
        super.input(sc);
        System.out.printf("Please enter the number of seats: ");
        while (true) {
            int tmp = Integer.parseInt(sc.nextLine());
            if (tmp < 0) {
                System.out.printf("The input is invalid! Please retype: ");
            } else {
                numberOfSeats = tmp;
                break;
            }
        }
    }

    @Override
    public double costPerKilometer() {
        return 0.5 * numberOfSeats;
    }

    @Override
    public void display() {
        super.display();
        System.out.printf("Number of seats: %d\n", numberOfSeats);
    }
}
