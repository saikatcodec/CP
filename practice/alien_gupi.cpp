#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        float x;
        cin >> x;

        int count = 0;
        while (x > 1.0)
        {
            count++;
            x /= 2;
        }

        cout << count << " days" << endl;
    }

    return 0;
}