#include <bits/stdc++.h>
using namespace std;

class Y; // For recognizeing y in friend function

class X
{
    int val;
    friend void swap(X &, Y &);

public:
    void insertData(int a)
    {
        val = a;
    }
    void printData(void)
    {
        cout << val << endl;
    }
};

class Y
{
    int val;
    friend void swap(X &, Y &);

public:
    void insertData(int a)
    {
        val = a;
    }
    void printData(void)
    {
        cout << val << endl;
    }
};

void swap(X &x1, Y &y1)
{
    int temp = x1.val;
    x1.val = y1.val;
    y1.val = temp;
}

int main()
{
    X n;
    Y m;

    n.insertData(34);
    m.insertData(56);

    swap(n, m);
    cout << "After swapping n ";
    n.printData();
    cout << "After swapping m ";
    m.printData();

    return 0;
}