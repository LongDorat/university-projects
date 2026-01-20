package practical_session_02.ex3;

import java.util.Scanner;

public class Fraction {
    private int num, denom;

    public Fraction() {
        num = 0;
        denom = 1;
    }

    public Fraction(int t, int m) {
        num = t;
        denom = m;
        reduce();
    }

    private void displayMessage(String message) {
        System.out.printf(message);
    }

    public void input(Scanner sc) {
        displayMessage("Please type in the number: ");
        num = sc.nextInt();

        do {
            displayMessage("Please type in the denominator, should not be 0: ");
            denom = sc.nextInt();

            if (denom != 0)
                break;
            else
                displayMessage("Please type again!");
        } while (true);

        reduce();
    }

    public void display() {
        if (num == 0)
            System.out.printf("0");
        else if (denom == 1)
            System.out.printf("%d", num);
        else
            System.out.printf("%d/%d", num, denom);
    }

    public void inverse() {
        if (num == 0) {
            throw new ArithmeticException("Cannot inverse a fraction with numerator 0");
        }

        int temp = num;
        num = denom;
        denom = temp;

        if (denom < 0) {
            num = -num;
            denom = -denom;
        }
    }

    public Fraction inverseValue() {
        if (num == 0) {
            throw new ArithmeticException("Cannot inverse a fraction with numerator 0");
        }
        return new Fraction(denom, num);
    }

    public float realValue() {
        return (float) num / denom;
    }

    public boolean greater(Fraction a) {
        return num * a.denom > a.num * denom;
    }

    public Fraction add(Fraction a) {
        int sharedDenom;
        int sumNum;
        if (denom != a.denom) {
            sharedDenom = denom * a.denom;
            sumNum = num * a.denom + a.num * denom;
        } else {
            sharedDenom = denom;
            sumNum = num + a.num;
        }

        return new Fraction(sumNum, sharedDenom);
    }

    public Fraction add(int n) {
        int sumNum = num + n * denom;

        return new Fraction(sumNum, denom);
    }

    private int gcd(int a, int b) {
        a = Math.abs(a);
        b = Math.abs(b);

        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }

        return a;
    }

    private void reduce() {
        if (num == 0) {
            denom = 1;
            return;
        }

        int gcdValue = gcd(num, denom);
        num /= gcdValue;
        denom /= gcdValue;

        if (denom < 0) {
            num = -num;
            denom = -denom;
        }
    }
}
