// C++ Program to find root of an
// equations using secant method
#include <bits/stdc++.h>
using namespace std;

// function takes value of x and returns f(x)
double f(double x) {
    // we are taking equation as x^4-3x^3+5x^2+5x-5
    return x * x * x * x - 3 * x * x * x + 5 * x * x + 5 * x - 5;
}

void secant(double a, double b, double E) {
    double c, es;
    int iter = 0;

    do {
        c = b - (f(b) * (a - b)) / (f(a) - f(b));
        es = fabs((c - b) / c) * 100;
        iter++;

        a = b;
        b = c;
    } while (es > 0.001);

    cout << "Root of the given equation = " << c << endl;
    cout << "No. of iterations = " << iter << endl;
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
