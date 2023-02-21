import java.util.Scanner;

abstract class Calculator {
    double result;

    public abstract void add(double x, double y);

    public abstract void subtract(double x, double y);

    public abstract void multiply(double x, double y);

    public abstract void divide(double x, double y);
}

class GeneralCalculator extends Calculator {
    @Override
    public void add(double x, double y) {
        result = x + y;
    }

    @Override
    public void subtract(double x, double y) {
        result = x - y;
    }

    @Override
    public void multiply(double x, double y) {
        result = x * y;
    }

    @Override
    public void divide(double x, double y) {
        result = x / y;
    }
}

class ScientificCalculator extends GeneralCalculator {
    public double power(double a, double b) {
        return Math.pow(a, b);
    }

    public double sin(double x) {
        return Math.sin(x);
    }

    public double cos(double x) {
        return Math.cos(x);
    }

    public double tan(double x) {
        return Math.tan(x);
    }

    public double log(double x) {
        return Math.log10(x);
    }

    public double sqrt(double x) {
        return Math.sqrt(x);
    }
}

class Calculate {
    public double radToDeg(double val) {
        return Math.PI * val / 180;
    }

    public void process() {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter type of calculator (general / Scientific):");
        String type = input.nextLine();

        System.out.println("Enter operation (+, -, *, /, sin, cos, tan, log, power, root):");
        char operation = input.next().charAt(0);
        System.out.println("Enter two operands:");
        double x = input.nextDouble();
        double y = input.nextDouble();

        if (type.equals("General") || type.equals("general")) {
            Boolean error = false;
            Calculator calculator = new GeneralCalculator();
            switch (operation) {
                case '+':
                    calculator.add(x, y);
                    break;
                case '-':
                    calculator.subtract(x, y);
                    break;
                case '*':
                    calculator.multiply(x, y);
                    break;
                case '/':
                    calculator.divide(x, y);
                    break;
                default:
                    System.out.print("No such operation");
                    error = true;
                    break;
            }
            if (!error) {
                System.out.println(x + " " + operation + " " + y + " = " + calculator.result);
            }
        } else if (type.equals("Scientific") || type.equals("scientific")) {
            Boolean doPrint = false;
            double result = -1;
            ScientificCalculator calculator = new ScientificCalculator();
            switch (operation) {
                case 'p':
                    result = calculator.power(x, y);
                    System.out.print(x + " to the power " + y + " is ");
                    break;
                case 's':
                    x = radToDeg(x);
                    result = calculator.sin(x);
                    System.out.print("sin x is ");
                    break;
                case 't':
                    x = radToDeg(x);
                    result = calculator.tan(x);
                    System.out.print("tan x is ");
                    break;
                case 'c':
                    x = radToDeg(x);
                    result = calculator.cos(x);
                    System.out.print("cos x is ");
                    break;
                case 'r':
                    result = calculator.sqrt(x);
                    System.out.print("square root x is ");
                    break;
                case 'l':
                    result = calculator.log(x);
                    System.out.print("log10 x is ");
                    break;
                default:
                    System.out.print("No such operation");
                    doPrint = false;
                    break;
            }
            if (!doPrint) {
                System.out.println(result);
            }
        } else {
            System.out.println("Invalid calculator type.");
        }

        input.close();
    }
}

public class Main {
    public static void main(String[] args) {
        System.out.println("=======Calculator========");

        Calculate clc;
        clc = new Calculate();
        clc.process();

    }
}
