#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return x * x * x * x - 3 * x * x * x + 5 * x * x + 5 * x - 5;
}

double dx(double x) {
    return 4 * x * x * x - 9 * x * x + 10 * x + 5;
}

double ddx(double x) {
    return 12 * x * x - 18 * x + 10;
}

int main() {
    double x;
    cin >> x;
    
    double root, es;
    int iter = 0;
    
    do {
        root = x - ((f(x) * dx(x)) / ((dx(x) * dx(x)) - (ddx(x) * f(x))));
        iter++;
        
        es = fabs((root - x) / root) * 100;
        x = root;
    } while (es > .0001);
    
    cout << root << endl;
    cout << iter << endl;

    return 0;
}