package practical_session_04_extend.ex2;

public class Bike extends Vehicle {
    public static int bikeCount = 0;
    private boolean hasGears;

    public Bike() {
        super();
        hasGears = false;
        bikeCount++;
    }

    @Override
    public void input(java.util.Scanner sc) {
        super.input(sc);
        System.out.printf("Does the bike have gears? (yes/no): ");
        String response = sc.nextLine();
        hasGears = response.equalsIgnoreCase("yes");
    }

    @Override
    public double costPerKilometer() {
        return 0;
    }

    @Override
    public void display() {
        super.display();
        System.out.printf("Has gears: %s\n", hasGears ? "Yes" : "No");
    }

}
