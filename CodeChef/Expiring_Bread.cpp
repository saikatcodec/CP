#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        int ans = n / k;
        if (n % k != 0)
            ans++;

        if (ans <= m)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}