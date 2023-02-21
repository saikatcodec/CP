#include <bits/stdc++.h>
using namespace std;

class Test
{
    int b;
    int a;

public:
    // constructor (args) : initialize section
    Test(int i, int j) : b(j), a(i + b)
    {
        cout << "a and b: " << a << "  " << b << endl;
    }
};

int main()
{
    Test t(5, 6);

    return 0;
}