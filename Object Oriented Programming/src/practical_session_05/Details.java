package practical_session_05;

public class Details {
    int amount;
    long unitPrice;

    Invoice invoice;
    Product product;

    public Details(int amount, long unitPrice, Invoice invoice, Product product) {
        this.amount = amount;
        this.unitPrice = unitPrice;
        this.invoice = invoice;
        this.product = product;
    }

    public void input() {}
    public void displayDetails() {
        System.out.printf("Product: %s - %s%n", product.id, product.name);
        System.out.printf("Total: %d x %,d = %,d%n", amount, unitPrice, amount * unitPrice);
    }
}
