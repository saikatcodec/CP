#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n;

        if (n < 1400)
            x = 4;
        else if (n < 1600)
            x = 3;
        else if (n < 1900)
            x = 2;
        else
            x = 1;

        cout << "Division " << x << endl;
    }

    return 0;
}