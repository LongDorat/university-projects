package practical_session_04_extend.ex2;

public class Motobike extends Vehicle {
    public static int motobikeCount = 0;
    private double engineDisplacement;
    private String displacementMeasurementUnit;

    public Motobike() {
        super();
        engineDisplacement = 0.0;
        displacementMeasurementUnit = "";
        motobikeCount++;
    }

    @Override
    public void input(java.util.Scanner sc) {
        super.input(sc);
        System.out.printf("Please enter the displacement measurement unit (e.g., liters, cc): ");
        displacementMeasurementUnit = sc.nextLine();
        System.out.printf("Please enter the engine displacement: ");
        while (true) {
            double tmp = Double.parseDouble(sc.nextLine());
            if (tmp < 0) {
                System.out.printf("The input is invalid! Please retype: ");
            } else {
                engineDisplacement = tmp;
                break;
            }
        }
    }

    @Override
    public double costPerKilometer() {
        return 0.1 * engineDisplacement;
    }

    @Override
    public void display() {
        super.display();
        System.out.printf("Engine displacement: %.2f %s\n", engineDisplacement, displacementMeasurementUnit);
    }

}
