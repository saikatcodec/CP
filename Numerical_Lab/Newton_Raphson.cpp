#include <math.h>

#include <iostream>
using namespace std;

/**
 * To calculate the volue of f(x) of an equation
 */
double fn(double x) {
    return x * x * x * x - 3 * x * x * x + 5 * x * x + 5 * x - 5;
}

/**
 * Defining derivative of de(x).
 * As you change fn(x), change this function also.
 */
double de(double x) {
    return 4 * x * x * x - 9 * x * x + 10 * x + 5;
}

int main() {
    double init, root;
    cout << "Function is x^4-3x^3+5x^2+5x-5" << endl;
    cout << "Enter initial root: ";
    cin >> init;

    double es = 0.0001, err;
    int iter = 0;

    do {
        iter++;

        // calculate root by newton raphson formula
        root = init - (fn(init) / de(init));
        err = fabs((root - init) / root) * 100;  // find error

        init = root;
    } while (err > es);

    cout << "The root is " << root << endl;
    cout << "Number of iteration: " << iter << endl;
    return 0;
}