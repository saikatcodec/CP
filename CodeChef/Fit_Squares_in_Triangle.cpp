#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int m = n / 2 - 1;

        m = (m * (m + 1)) / 2;

        cout << m << endl;
    }

    return 0;
}