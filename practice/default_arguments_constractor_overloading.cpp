#include <bits/stdc++.h>
using namespace std;

class Complex
{
    int a, b;

public:
    Complex()
    {
        a = 0;
        b = 0;
    }
    Complex(int x, int y = 0)
    {
        a = x;
        b = y;
    }

    void printN(void)
    {
        cout << "Complex number is " << a << " + " << b << "i" << endl;
    }
};

int main()
{
    Complex c1;
    c1.printN();

    Complex c2(3, 5);
    c2.printN();

    Complex c3(2);
    c3.printN();

    return 0;
}