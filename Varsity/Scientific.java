import java.util.Scanner;

abstract class Calculator {
    double num1, num2;
    Scanner sc = new Scanner(System.in);

    void getNumbers() {
        System.out.print("Enter first number: ");
        num1 = sc.nextDouble();
        System.out.print("Enter second number: ");
        num2 = sc.nextDouble();
    }

    abstract void displayResult();
}

class Addition extends Calculator {
    void displayResult() {
        System.out.println("Result: " + (num1 + num2));
    }
}

class Subtraction extends Calculator {
    void displayResult() {
        System.out.println("Result: " + (num1 - num2));
    }
}

class Multiplication extends Calculator {
    void displayResult() {
        System.out.println("Result: " + (num1 * num2));
    }
}

class Division extends Calculator {
    void displayResult() {
        System.out.println("Result: " + (num1 / num2));
    }
}

class ScientificCalculator extends Calculator {
    void displayResult() {
        System.out.println("Result: " + (Math.pow(num1, num2)));
    }
}

public class Scientific {
    public static void main(String[] args) {
        int choice;
        Scanner sc = new Scanner(System.in);

        System.out.println("1. Addition");
        System.out.println("2. Subtraction");
        System.out.println("3. Multiplication");
        System.out.println("4. Division");
        System.out.println("5. Scientific Calculation");
        System.out.print("Enter your choice: ");
        choice = sc.nextInt();

        Calculator c = null;
        switch (choice) {
            case 1:
                c = new Addition();
                break;
            case 2:
                c = new Subtraction();
                break;
            case 3:
                c = new Multiplication();
                break;
            case 4:
                c = new Division();
                break;
            case 5:
                c = new ScientificCalculator();
                break;
            default:
                System.out.println("Invalid choice");
                System.exit(0);
        }
        c.getNumbers();
        c.displayResult();

        sc.close();
    }
}
