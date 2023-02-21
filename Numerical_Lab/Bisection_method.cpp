#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return x * x * x * x - 3 * x * x * x + 5 * x * x + 5 * x - 5;
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

    double preci;
    cout << "Estimate precision (0.0001): ";
    cin >> preci;

    double ans;

    while ((high - low) >= preci) {
        double mid = low + (high - low) / 2;
        
        if (f(low) * f(mid) == 0) {
            ans = mid;
            break;
        } else if (f(low) * f(mid) < 0) {
            high = mid;
        } else {
            low = mid;
        }
    }

    cout << "Root of function: " << high << endl;

    return 0;
}