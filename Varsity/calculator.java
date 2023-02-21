import java.util.Scanner;

abstract class Calculator {
    int num1, num2;

    Calculator(int num1, int num2) {
        this.num1 = num1;
        this.num2 = num2;
    }

    abstract int calculate();
}

class Addition extends Calculator {
    Addition(int num1, int num2) {
        super(num1, num2);
    }

    int calculate() {
        return num1 + num2;
    }
}

class Subtraction extends Calculator {
    Subtraction(int num1, int num2) {
        super(num1, num2);
    }

    int calculate() {
        return num1 - num2;
    }
}

class Multiplication extends Calculator {
    Multiplication(int num1, int num2) {
        super(num1, num2);
    }

    int calculate() {
        return num1 * num2;
    }
}

class Division extends Calculator {
    Division(int num1, int num2) {
        super(num1, num2);
    }

    int calculate() {
        if (num2 == 0) {
            return -1;
        }

        return num1 / num2;
    }
}

class Modulus extends Calculator {
    Modulus(int num1, int num2) {
        super(num1, num2);
    }

    int calculate() {
        if (num2 == 0) {
            return -1;
        }

        return num1 % num2;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner read = new Scanner(System.in);
        System.out.println("========== Calculator ==========");
        boolean start = true;

        while (start) {
            int num1, num2;
            Character operator;
            System.out.print("Enter two number: ");

            num1 = read.nextInt();
            num2 = read.nextInt();

            System.out.print("Enter operator (+, -, *, /, %): ");
            operator = read.next().charAt(0);

            switch (operator) {
                case '+':
                    Calculator add = new Addition(num1, num2);
                    System.out.println(num1 + " + " + num2 + " = " + add.calculate());
                    break;
                case '-':
                    Calculator sub = new Subtraction(num1, num2);
                    System.out.println(num1 + " - " + num2 + " = " + sub.calculate());
                    break;
                case '*':
                    Calculator mul = new Multiplication(num1, num2);
                    System.out.println(num1 + " * " + num2 + " = " + mul.calculate());
                    break;
                case '/':
                    Calculator div = new Division(num1, num2);
                    int value = div.calculate();
                    if (value == -1) {
                        System.out.println("Division is not possible");
                    } else {
                        System.out.println(num1 + " / " + num2 + " = " + value);
                    }
                    break;
                case '%':
                    Calculator mod = new Modulus(num1, num2);
                    int rem = mod.calculate();
                    if (rem == -1) {
                        System.out.println("Reminder is not possible");
                    } else {
                        System.out.println(num1 + " % " + num2 + " = " + rem);
                    }
                    break;
                default:
                    System.out.println("Invalid operation");
            }

            System.out.println();
            Character choice;
            System.out.print("Continue (Y/n): ");
            choice = read.next().charAt(0);

            if (choice == 'n' || choice == 'N') {
                start = false;
            } else {
                start = true;
            }
        }
        read.close();
    }
}
