#include <bits/stdc++.h>
using namespace std;

/**
 * To calculate the volue of f(x) of an equation
 */
double f(double x) {
    return (x * x * x * x - 3 * x * x * x + 5 * x * x + 5 * x - 5);
}

/**
 * Write f(x) as x = g(x) and
 * define g(x) here
 */
double g(double x) {
    return (-x * x * x * x + 3 * x * x * x - 5 * x * x + 5) / 5;
}

/**
 * calculate fixed position
 */
void fixedPos(double x0, double es) {
    int iter = 0; // Count iteration
    double xrold, xr = x0;
    do {
        xrold = xr; // old root 
        xr = g(xrold); // calculate new root
        iter++; // increement iteration

        // if iter cross the max iteration terminate the calculation
        if (iter > 1e6) {
            cout << "Not Convergent.";
            return;
        }
    } while (fabs(f(xr)) > es);

    // Print root and number of iteration
    cout << "Root of the function " << xr << endl;
    cout << "Number of iteration: " << iter << endl;
}

int main() {
    double low, es = 0.0001;
    cout << "The function x^4-3x^3+5x^2+5x-5" << endl;
    cout << "Estimate root: ";
    cin >> low;

    fixedPos(low, es);

    return 0;
}