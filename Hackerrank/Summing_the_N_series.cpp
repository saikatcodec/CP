#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int sum = 0;
        long long n;
        cin >> n;

        n %= MOD;
        sum = (n * n) % MOD;

        cout << sum << "\n";
    }

    return 0;
}
