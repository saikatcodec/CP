#include <cmath>
#include <iostream>
using namespace std;

class Calculator {
   public:
    int add(int a, int b) {
        return a + b;
    }

    int subtract(int a, int b) {
        return a - b;
    }

    int multiply(int a, int b) {
        return a * b;
    }

    int divide(int a, int b) {
        return a / b;
    }

    int modulus(int a, int b) {
        return a % b;
    }
};

int main() {
    Calculator calculator;
    bool start = true;

    while (start) {
        int a, b;
        char operation;

        cout << "Enter first number: ";
        cin >> a;

        cout << "Enter second number: ";
        cin >> b;

        cout << "Enter operation (+, -, *, /):" << endl;
        cout << "Enter 0 to exit: ";
        cin >> operation;

        switch (operation) {
            case '+':
                cout << a << " + " << b << " = " << calculator.add(a, b) << endl;
                break;
            case '-':
                cout << a << " - " << b << " = " << calculator.subtract(a, b) << endl;
                break;
            case '*':
                cout << a << " * " << b << " = " << calculator.multiply(a, b) << endl;
                break;
            case '/':
                cout << a << " / " << b << " = " << calculator.divide(a, b) << endl;
                break;
            case '%':
                cout << a << " % " << b << " = " << calculator.modulus(a, b) << endl;
                break;
            case '0':
                start = false;
                break;
            default:
                cout << "Invalid operation" << endl;
        }
    }

    return 0;
}
