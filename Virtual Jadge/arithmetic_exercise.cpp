#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, k;
    cin >> a >> b >> k;

    double result = a / (b * 1.0);

    cout << fixed << setprecision(k) << result << "\n";

    return 0;
}