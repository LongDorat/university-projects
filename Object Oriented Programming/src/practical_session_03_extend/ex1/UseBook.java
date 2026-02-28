package practical_session_03_custom.ex1;

import java.util.Scanner;

public class UseBook {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n;
        System.out.print("Enter number of books: ");
        n = sc.nextInt();

        Book[] books = new Book[n];
        for (int i = 0; i < n; i++) {
            System.out.println("Book " + (i + 1) + ":");
            books[i] = new Book();
            books[i].input(sc);
            System.out.println();
        }

        // Display all books
        for (int i = 0; i < n; i++) {
            System.out.println("Book " + (i + 1) + ":");
            books[i].display();
            System.out.println();
        }

        // Find most expensive book
        Book mostExpensive = books[0];
        for (int i = 1; i < n; i++) {
            if (books[i].priceAfterDiscount(0) > mostExpensive.priceAfterDiscount(0)) {
                mostExpensive = books[i];
            }
        }
        System.out.println("Most expensive book:");
        mostExpensive.display();
        System.out.println();

        // Find book with the most pages
        Book mostPages = books[0];
        for (int i = 1; i < n; i++) {
            if (books[i].getPages() > mostPages.getPages()) {
                mostPages = books[i];
            }
        } 
        System.out.println("Book with most pages:");
        mostPages.display();
        System.out.println();

        // Books with the same author as the first book
        System.out.println("Books with the same author as the first book:");
        for (int i = 1; i < n; i++) {
            if (books[i].isSameAuthor(books[0])) {
                books[i].display();
            }
        }
        System.out.println();

        // Selling price of each book with 20% discount
        System.out.println("Selling price of each book with 20% discount:");
        for (int i = 0; i < n; i++) {
            System.out.printf("%s: $%.2f\n", books[i].getName(), books[i].priceAfterDiscount(20));
        }

        sc.close();
    }
}
