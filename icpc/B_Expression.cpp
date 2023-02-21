#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int arr[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + 3);
    int prod;
    if (arr[0] == 1)
    {
        int sum = arr[0] + arr[1];
        prod = sum * arr[2];
    }
    else
    {
        prod = arr[0] * arr[1] * arr[2];
    }

    cout << prod << nl;

    return 0;
}