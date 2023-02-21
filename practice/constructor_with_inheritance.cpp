#include <bits/stdc++.h>
using namespace std;

class Base1
{
    int data1;

public:
    Base1(int i)
    {
        data1 = i;
        cout << "Base1 is called" << endl;
    }
};

class Base2
{
    int data2;

public:
    Base2(int i)
    {
        data2 = i;
        cout << "Base2 is called" << endl;
    }
};

class Derived : public Base1, public Base2
{
    int data3;

public:
    Derived(int a, int b, int c) : Base1(a), Base2(b)
    {
        data3 = c;
    }

    void printData(void)
    {
        cout << "Noting to print" << endl;
    }
};

int main()
{
    Derived d(5, 4, 6);
    d.printData();

    return 0;
}