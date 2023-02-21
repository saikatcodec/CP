#include <iostream>
using namespace std;

void solve(void)
{
    int n, p, x, y;
    cin >> n >> p >> x >> y;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int zero = 0, one = 0;

    for (int i = 0; i < p; i++)
    {
        if (arr[i] == 0)
            zero++;
        else if (arr[i] == 1)
            one++;
    }

    cout << (zero * x) + (one * y) << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}