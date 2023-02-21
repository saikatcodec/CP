#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int temp;
        cin >> temp;

        if (temp > 20)
            cout << "HOT\n";
        else
            cout << "COLD\n";
    }

    return 0;
}