#include <iostream>
using namespace std;

bool isEven(int n)
{
    if (n & 1)
        return false;

    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        bool even = isEven(n);

        if (even)
            cout << "Even" << endl;
        else
            cout << "Odd" << endl;
    }

    return 0;
}