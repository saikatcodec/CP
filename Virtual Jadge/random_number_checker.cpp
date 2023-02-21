#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, oddCnt = 0, evnCnt = 0;
    cin >> n;

    long long arr[n];
    for (long long i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] & 1)
            oddCnt++;
        else
            evnCnt++;
    }

    if (abs(oddCnt - evnCnt) <= 1)
        cout << "Good\n";
    else
        cout << "Not Good\n";

    return 0;
}