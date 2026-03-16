package practical_session_05;

public class Customer {
    String id;
    String name;
    String address;

    public void inputCustomer(java.util.Scanner scanner) {
        System.out.print("Enter customer ID: ");
        this.id = scanner.nextLine();
        System.out.print("Enter customer name: ");
        this.name = scanner.nextLine();
        System.out.print("Enter customer address: ");
        this.address = scanner.nextLine();
    }
    public void displayCustomer() {
        System.out.println("Customer ID: " + id);
        System.out.println("Customer Name: " + name);
        System.out.println("Customer Address: " + address);
    }
}
