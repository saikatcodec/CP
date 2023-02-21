#include <bits/stdc++.h>
using namespace std;

class complex_num
{
    int a, b;

public:
    void setNum(void)
    {
        cout << "Enter two number ";
        cin >> a >> b;
    }

    void printNum(void)
    {
        cout << "Complex number is " << a << " + " << b << "i" << endl;
    }

    void addComplex(complex_num o1, complex_num o2);
};

void complex_num ::addComplex(complex_num o1, complex_num o2)
{
    a = o1.a + o2.a;
    b = o1.b + o2.b;
}

int main()
{

    complex_num o1, o2, o3;

    o1.setNum();
    o1.printNum();

    o2.setNum();
    o2.printNum();

    o3.addComplex(o1, o2);
    o3.printNum();

    return 0;
}