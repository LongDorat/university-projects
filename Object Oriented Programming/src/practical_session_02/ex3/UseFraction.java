package practical_session_02.ex3;

import java.util.Scanner;

public class UseFraction {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        Fraction x = new Fraction();
        Fraction y = new Fraction();
        x.input(sc);
        y.input(sc);

        Fraction inverseX = x.inverseValue();
        inverseX.display();
        System.out.println();

        Fraction sumXY = x.add(y);
        sumXY.display();
        System.out.println();

        System.out.printf("Please type in n: ");
        int n = sc.nextInt();

        Fraction[] list = new Fraction[n];
        Fraction sumList = new Fraction();
        for (int i = 0; i < n; i++) {
            list[i] = new Fraction();
            list[i].input(sc);

            sumList = sumList.add(list[i]);
        }
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
    }
}
