package practical_session_03_extend.ex1;

import java.util.Scanner;

public class Book {
    private String name;
    private String author;
    private int numberOfPages;
    private double price;
    private int publishYear;

    public Book(){
        name = null;
        author = null;
        numberOfPages = 0;
        price = 0.0;
        publishYear = 0;
    }

    public Book(String name, String author, int numberOfPages, double price, int publishYear) {
        this.name = name;
        this.author = author;
        this.numberOfPages = numberOfPages;
        this.price = price;
        this.publishYear = publishYear;
    }

    public Book(Book other){ 
        this.name = other.name;
        this.author = other.author;
        this.numberOfPages = other.numberOfPages;
        this.price = other.price;
        this.publishYear = other.publishYear;
    }

    public void display(){
        System.out.printf("%s by %s, %d pages, published in %d, price: $%.2f\n", name, author, numberOfPages, publishYear, price);
    }

    public void input(Scanner sc){
        sc.nextLine(); // Consume the leftover newline
        
        System.out.print("Enter book name: ");
        name = sc.nextLine();
        System.out.print("Enter author name: ");
        author = sc.nextLine();
        System.out.print("Enter number of pages: ");
        numberOfPages = sc.nextInt();
        System.out.print("Enter price: ");
        price = sc.nextDouble();
        System.out.print("Enter publish year: ");
        publishYear = sc.nextInt();
    }

    public double priceAfterDiscount(double discountPercentage){
        return price * (1 - discountPercentage / 100);
    }

    public boolean isSameAuthor(Book other){
        return this.author.equals(other.author);
    }

    public boolean isMoreExpensiveThan(Book other){
        return this.price > other.price;
    }

    // Getters
    public String getName() {
        return name;
    }

    public int getPages(){
        return numberOfPages;
    }
}
