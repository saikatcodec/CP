#include <bits/stdc++.h>
using namespace std;

class Complex
{
    int a, b;

public:
    // Give access to the non member function to access the private data of the class
    friend Complex sumComplex(Complex o1, Complex o2);

    void setNum(int n1, int n2);
    void printNum(void);
};

void Complex ::setNum(int n1, int n2)
{
    a = n1;
    b = n2;
}

void Complex ::printNum(void)
{
    cout << "Complex number is " << a << " + " << b << "i" << endl;
}

/**
 * @brief Its a non member function to return two complex number object
 *
 * @param o1
 * @param o2
 * @return Complex
 */
Complex sumComplex(Complex o1, Complex o2)
{
    Complex o3;
    o3.setNum(o1.a + o2.a, o1.b + o2.b);
    return o3;
}

int main()
{
    Complex o1, o2, sum;

    o1.setNum(1, 2);
    o2.setNum(4, 5);

    sum = sumComplex(o1, o2);
    sum.printNum();

    return 0;
}