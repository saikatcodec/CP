#include <cmath>
#include <iostream>
using namespace std;

/**
 * To calculate the volue of f(x) of an equation
 */
double f(double x) {
    // replace this with the actual function you want to find the root of
    return x * x * x * x - 3 * x * x * x + 5 * x * x + 5 * x - 5;
}

// Prints root of func(x) in interval [a, b]
void regulaFalsi(double a, double b) {
    cout << "Loading..." << endl;
    int iter = 0; // For count the iteration
    double c = a, fn;  // Initialize result
    double es = 0.0001;

    do {
        // Find the point that touches x axis
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        // Check if the above found point is root
        fn = f(c);
        if (fn == 0)
            break;

        // Decide the side to repeat the steps
        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;

        iter++;
    } while (fabs(fn) >= es);

    
    cout << "Root of the function " << c << endl;
    cout << "After the " << iter << " no of iteration" << endl;
}

int main() {
    double low, high;
    cout << "The function x^4-3x^3+5x^2+5x-5" << endl;
    cout << "Enter range to find the root: ";
    cin >> low >> high;

    if (f(low) * f(high) > 0) {
        cout << "Root may not be lie" << endl;
        exit(0);
    }

    regulaFalsi(low, high);

    return 0;
}