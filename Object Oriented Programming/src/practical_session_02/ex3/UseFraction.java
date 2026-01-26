package practical_session_02.ex3;

import java.util.Scanner;

public class UseFraction {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Fraction x = new Fraction();
        Fraction y = new Fraction();
        System.out.println("Please type in the fraction for x:");
        x.input(sc);
        System.out.println("Please type in the fraction for y:");
        y.input(sc);

        Fraction inverseX = x.inverseValue();
        System.out.printf("Inverses of X is: ");
        inverseX.display();
        System.out.println();

        Fraction sumXY = x.add(y);
        System.out.printf("Sum of X and Y is: ");
        sumXY.display();
        System.out.println();

        System.out.printf("Please type in n: ");
        int n;
        do {
            n = sc.nextInt();
        } while (n <= 0);

        Fraction[] list = new Fraction[n];
        Fraction sumList = new Fraction();
        for (int i = 0; i < n; i++) {
            System.out.println("Please type in fraction number " + (i + 1) + ": ");
            list[i] = new Fraction();
            list[i].input(sc);

            sumList = sumList.add(list[i]);
        }
        System.out.printf("Sum of the list is: ");
        sumList.display();
        System.out.println();

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (list[i].greater(list[j])) {
                    Fraction temp = list[i];
                    list[i] = list[j];
                    list[j] = temp;
                }
            }
        }

        System.out.printf("The largest fraction is: ");
        list[n - 1].display();
        System.out.println();

        for (int i = 0; i < n; i++) {
            list[i].display();
            System.out.print(" ");
        }

        sc.close();
    }
}
