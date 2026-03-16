package practical_session_05;

public class VIPCustomer extends Customer{
    int discount;
    Date birthDate;

    public VIPCustomer(int discount, Date birthDate) {
        super();
        this.discount = discount;
        this.birthDate = birthDate;
    }

    public void inputCustomer(java.util.Scanner scanner) {
        super.inputCustomer(scanner);
        System.out.print("Enter discount: ");
        this.discount = scanner.nextInt();
        System.out.print("Enter birth date: ");
        this.birthDate = new Date();
        this.birthDate.inputDate(scanner);
    }

    public void displayCustomer() {
        super.displayCustomer();
        System.out.println("Discount: " + discount);
        System.out.print("Birth Date: ");
        birthDate.displayDate();
    }
}
