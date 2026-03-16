package practical_session_05;

import java.util.ArrayList;
import java.util.List;

public class Invoice {
    String inNo;
    String billTo;
    Date billDate;

    Customer customer;
    List<Details> items = new ArrayList<>();

    public void inputInvoice(java.util.Scanner scanner) {
        FormatPrint.printBanner("Enter Invoice Information");
        System.out.print("Enter invoice number: ");
        this.inNo = scanner.nextLine();
        System.out.print("Enter bill to: ");
        this.billTo = scanner.nextLine();
        System.out.print("Enter bill date: ");
        this.billDate = new Date();
        this.billDate.inputDate(scanner);
        System.out.println("Enter customer information:");
        this.customer = new Customer();
        this.customer.inputCustomer(scanner);

        System.out.print("Enter number of items: ");
        int n = Integer.parseInt(scanner.nextLine());
        for (int i = 0; i < n; i++) {
            System.out.println("Enter information for item " + (i + 1) + ":");
            Product product = new Product();
            product.inputProduct(scanner);
            System.out.print("Enter amount: ");
            int amount = Integer.parseInt(scanner.nextLine());
            System.out.print("Enter unit price: ");
            long unitPrice = Long.parseLong(scanner.nextLine());
            Details details = new Details(amount, unitPrice, this, product);
            items.add(details);
        }
    }

    public void displayInvoice() {
        FormatPrint.printBanner("Invoice Information");
        FormatPrint.printLeftRightAligned("Bill Number", inNo, 20);
        FormatPrint.printLeftRightAligned("Bill To", billTo, 20);
        System.out.print("Build Date: ");
        billDate.displayDate();
        System.out.println("Customer Information:");
        customer.displayCustomer();
        System.out.println("Items:");
        for (Details item : items) {
            item.displayDetails();
        }
    }

    public long total() {
        long total = 0;
        for (Details item : items) {
            total += item.amount * item.unitPrice;
        }
        return total;
    }
}
