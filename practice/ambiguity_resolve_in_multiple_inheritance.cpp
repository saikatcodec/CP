#include <bits/stdc++.h>
using namespace std;

class Base1
{
public:
    void greet();
};

void Base1 ::greet()
{
    cout << "Hi! Good Morning." << endl;
}

class Base2
{
public:
    void greet();
};

void Base2 ::greet()
{
    cout << "Hi! Good Evening." << endl;
}

class Child : public Base1, public Base2
{
    int a = 10;

public:
    // To resolved the ambiguity we need to declare a function in child class
    void greet();
};

void Child ::greet()
{
    Base2 ::greet();
}

int main()
{
    Child cd;
    cd.greet();

    return 0;
}