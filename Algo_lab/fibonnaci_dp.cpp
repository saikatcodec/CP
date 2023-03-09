#include <iostream>
#include <cmath>

using namespace std;

double func(double x) {
    // Define the function whose roots you want to find
    return (x * x) - 4;
}

double derivative(double x) {
    // Define the derivative of the function
    return 2 * x;
}

double modified_newton_raphson(double x0) {
    double x = x0;
    double f = func(x);
    double f_prime = derivative(x);
    double epsilon = 1e-6; // Set a tolerance value for convergence
    int max_iterations = 100; // Set a maximum number of iterations to prevent infinite loops

    for (int i = 0; i < max_iterations; i++) {
        double x_next = x - (f / f_prime); // Compute the next approximation of the root
        double f_next = func(x_next);
        double f_prime_next = derivative(x_next);

        if (abs(f_next) < epsilon) { // Check if we've converged to the root
            return x_next;
        }

        // Update x, f, and f_prime for the next iteration
        x = x_next;
        f = f_next;
        f_prime = f_prime_next;
    }

    // If we haven't converged after the maximum number of iterations, return NaN to indicate failure
    return nan("");
}

int main() {
    double x0 = 2; // Set an initial guess for the root
    double root = modified_newton_raphson(x0);

    if (isnan(root)) {
        cout << "Failed to converge to a root" << endl;
    } else {
        cout << "Root: " << root << endl;
    }

    return 0;
}
