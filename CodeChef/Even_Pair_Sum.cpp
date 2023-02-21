#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long a, b, evenA, evenB, oddA, oddB;
        cin >> a >> b;

        if (a % 2 == 0)
        {
            evenA = a / 2;
            oddA = a / 2;
        }
        else
        {
            oddA = a / 2 + 1;
            evenA = a / 2;
        }

        if (b % 2 == 0)
        {
            evenB = b / 2;
            oddB = b / 2;
        }
        else
        {
            oddB = b / 2 + 1;
            evenB = b / 2;
        }

        cout << (a * b) - (evenA * oddB + evenB * oddA) << endl;
    }

    return 0;
}