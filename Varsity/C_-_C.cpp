#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, a, b;
    cin >> n >> a >> b;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int sum = 0;
    for (int i = a; i <= b; i++)
    {
        sum += arr[i];
    }

    cout << sum << nl;

    return 0;
}