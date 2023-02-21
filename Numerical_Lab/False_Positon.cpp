#include <cmath>
#include <iostream>
using namespace std;

double f(double x) {
    // replace this with the actual function you want to find the root of
    return x * x * x * x - 3 * x * x * x + 5 * x * x + 5 * x - 5;
}

double ModFalsePos(double xl, double xu, double es, double &ea, int &iter) {
    iter = 1e9;
    double xr;
    double fl = f(xl);
    double fu = f(xu);

    while (iter--) {
        double xrold = xr;
        xr = xu - fu * (xl - xu) / (fl - fu);
        double fr = f(xr);

        if (xr != 0) {
            ea = fabs((xr - xrold) / xr) * 100;
        }
        double test = fl * fr;
        if (test < 0) {
            xu = xr;
            fu = f(xu);
        } else if (test > 0) {
            xl = xr;
            fl = f(xl);
        } else {
            ea = 0;
        }
        if (ea < es) {
            break;
        }
    }

    return xr;
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

    double es, ea;
    int iter;
    cout << "Estimate error (0.0001): ";
    cin >> es;

    double root = ModFalsePos(low, high, es, ea, iter);

    cout << "Root of the function " << root << endl;
    cout << "Appoximate error: " << ea << endl;
    cout << "Number of iteration: " << 1e9 - iter << endl;

    return 0;
}