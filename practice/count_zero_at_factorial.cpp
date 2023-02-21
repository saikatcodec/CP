#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, count = 0;
        cin >> n;

        while (true)
        {
            count += n / 5;
            if (n % 5 != 0)
                break;
            n /= 5;
        }

        cout << count << endl;
    }

    return 0;
}