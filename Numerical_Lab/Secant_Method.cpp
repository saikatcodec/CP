// C++ Program to find root of an
// equations using secant method
#include <bits/stdc++.h>
using namespace std;

// function takes value of x and returns f(x)
double f(double x) {
    // we are taking equation as x^4-3x^3+5x^2+5x-5
    return x * x * x * x - 3 * x * x * x + 5 * x * x + 5 * x - 5;
}

void secant(double x1, double x2, double E) {
    double iter = 0, xm, x0, c;
    if (f(x1) * f(x2) < 0) {
        do {
            // calculate the intermediate value
            x0 = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));

            // check if x0 is root of equation or not
            c = f(x1) * f(x0);

            // update the value of interval
            x1 = x2;
            x2 = x0;

            // update number of iteration
            iter++;

            // if x0 is the root of equation then break the loop
            if (c == 0)
                break;
            xm = (x1 * f(x2) - x2 * f(x1)) / (f(x2) - f(x1));
        } while (fabs(xm - x0) >= E);  // repeat the loop
                                       // until the convergence

        cout << "Root of the given equation=" << x0 << endl;
        cout << "No. of iterations = " << iter << endl;
    } else
        cout << "Can not find a root in the given interval";
}

// Driver code
int main() {
    // initializing the values
    double x1, x2, E = 0.0001;
    cout << "Function is x^4-3x^3+5x^2+5x-5" << endl;
    cout << "Enter two guess (0 1): ";
    cin >> x1 >> x2;

    secant(x1, x2, E);

    return 0;
}
