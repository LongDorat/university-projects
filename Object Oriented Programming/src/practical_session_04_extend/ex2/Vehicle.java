package practical_session_04_extend.ex2;

public abstract class Vehicle {
    protected String vehicleName;
    protected String color;
    protected int producedYear;

    public Vehicle(){
        vehicleName = "";
        color = "";
        producedYear = 0;
    }

    public void input(java.util.Scanner sc){
        System.out.printf("Please enter vehicle name: ");
        vehicleName = sc.nextLine();
        System.out.printf("Please enter the color of the vehicle: ");
        color = sc.nextLine();
        System.out.printf("Please enter the production year: ");
        while (true){
            int tmp = Integer.parseInt(sc.nextLine());
            if (tmp < 0){
                System.out.printf("The input is invalid! Please retype: ");
            } else {
                producedYear = tmp;
                break;
            }
        }
    }

    public abstract double costPerKilometer();

    public double costForDistance(double distance){
        return costPerKilometer() * distance;
    }

    public void display(){
        System.out.printf("Vehicle name: %s\n", vehicleName);
        System.out.printf("Color: %s\n", color);
        System.out.printf("Produced year: %d\n", producedYear);
        System.out.printf("Cost per kilometer: %.2f\n", costPerKilometer());
    }
}
