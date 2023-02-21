#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, init, lastI, sum = 0;
    cin >> n >> init >> lastI;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = init; i <= lastI; i++)
        sum += arr[i];

    cout << sum << endl;

    return 0;
}