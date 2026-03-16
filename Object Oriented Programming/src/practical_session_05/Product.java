package practical_session_05;

public class Product {
    String id;
    String name;

    Date manufacturedDate;

    public void inputProduct(java.util.Scanner scanner) {
        System.out.print("Enter product ID: ");
        this.id = scanner.nextLine();
        System.out.print("Enter product name: ");
        this.name = scanner.nextLine();
        System.out.println("Enter manufactured date: ");
        this.manufacturedDate = new Date();
        this.manufacturedDate.inputDate(scanner);
    }
    public void displayProduct() {
        System.out.println("Product ID: " + id);
        System.out.println("Product Name: " + name);
        System.out.print("Manufactured Date: ");
        manufacturedDate.displayDate();
    }
}
