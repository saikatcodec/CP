#include <iostream>
using namespace std;

int main()
{
    int t, tl;
    cin >> t;
    tl = t;

    while (t--)
    {
        int n;
        cin >> n;

        cout << "Case " << tl - t << ":";
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
                cout << " " << i;
        }

        cout << endl;
    }

    return 0;
}