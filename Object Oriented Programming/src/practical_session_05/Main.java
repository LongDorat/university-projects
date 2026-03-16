package practical_session_05;

public class Main {
    public static void main(String[] args) {
        FormatPrint.printBanner("Welcome to the Invoice System");

        java.util.Scanner scanner = new java.util.Scanner(System.in);
        int n;
        System.out.print("Enter number of invoices: ");
        n = Integer.parseInt(scanner.nextLine());

        Invoice[] invoices = new Invoice[n];
        for (int i = 0; i < n; i++) {
            invoices[i] = new Invoice();
            invoices[i].inputInvoice(scanner);
        }

        // All invoice that has total amount less than 1.000.000 vnd
        FormatPrint.printBanner("Invoices with total amount less than 1.000.000 VND");
        for (Invoice invoice : invoices) {
            if (invoice.total() < 1000000) {
                invoice.displayInvoice();
                System.out.println("Total Amount: " + invoice.total());
                System.out.println();
            }
        }

        // All invoice's customer that were issued on 20/05/2025
        FormatPrint.printBanner("Invoices issued on 20/05/2025");
        for (Invoice invoice : invoices) {
            if (invoice.billDate.isTheDate(20, 5, 2025)) {
                invoice.displayInvoice();
                System.out.println();
            }
        }
    }
}
