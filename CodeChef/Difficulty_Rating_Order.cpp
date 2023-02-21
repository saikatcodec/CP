#include <bits/stdc++.h>
using namespace std;

inline bool non_dec(int first, int last)
{
    return first < last;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        bool sorted = is_sorted(arr, arr + n, non_dec);

        if (sorted)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}