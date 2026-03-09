package practical_session_04_extend.ex2;

public class Main {
    public static void main(String[] args){
        java.util.Scanner sc = new java.util.Scanner(System.in);

        int n;
        System.out.print("Enter number of vehicles: ");
        n = Integer.parseInt(sc.nextLine());

        Vehicle[] vehicles = new Vehicle[n];
        for (int i = 0; i < n; i++) {
            System.out.printf("Vehicle %d:\n", i + 1);
            System.out.print("Enter vehicle type (Car/Bike/Motobike): ");
            String type = sc.nextLine();
            switch (type.toLowerCase()) {
                case "car":
                    vehicles[i] = new Car();
                    break;
                case "bike":
                    vehicles[i] = new Bike();
                    break;
                case "motobike":
                    vehicles[i] = new Motobike();
                    break;
                default:
                    System.out.println("Invalid vehicle type! Defaulting to Car.");
                    vehicles[i] = new Car();
            }
            vehicles[i].input(sc);
        }

        for (int i = 0; i < n; i++) {
            System.out.printf("Vehicle %d details:\n", i + 1);
            vehicles[i].display();
            System.out.printf("Cost per kilometer: %.2f\n", vehicles[i].costPerKilometer());
        }

        for (Vehicle vehicle : vehicles) {
            int distance = 100;
            System.out.printf("Total cost for %d kilometers: %.2f\n", distance, vehicle.costForDistance(distance));
        }

        System.out.printf("Total number of cars: %d\n", Car.carCount);
        System.out.printf("Total number of bikes: %d\n", Bike.bikeCount);
        System.out.printf("Total number of motobikes: %d\n", Motobike.motobikeCount);

        sc.close();
    }
}
