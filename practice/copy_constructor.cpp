#include <bits/stdc++.h>
using namespace std;

class Number
{
    int a;

public:
    int b;
    Number() {}
    Number(int x, int y)
    {
        a = x;
        b = y;
    }

    // If copy constructor is not present then compiler provide its own copy construnctor
    Number(Number &obj)
    {
        cout << "Copy constructor called" << endl;
        a = obj.a;
        b = obj.b;
    }

    void printN()
    {
        cout << "Numbers are " << a << " " << b << endl;
    }
};

int main()
{
    Number n;
    n = Number(3, 5);
    n.printN();

    Number m(n);
    m.printN();

    n.b = 34;
    n.printN();
    m.printN();

    return 0;
}