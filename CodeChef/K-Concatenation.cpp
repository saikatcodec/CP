#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

typedef long long ll;

ll kadans(int arr[], int n)
{
    ll max_sum = INT_MIN, current_max_sum = 0;
    for (int i = 0; i < n; i++)
    {
        current_max_sum += arr[i];

        if (max_sum < current_max_sum)
            max_sum = current_max_sum;

        if (current_max_sum <= 0)
            current_max_sum = 0;
    }

    return max_sum;
}

ll solve(int arr[], int n, int k)
{
    ll kadans_sum = kadans(arr, n);
    ll crn_prf_sum = 0, crn_srf_sum = 0;
    ll max_prf_sum = 0, max_srf_sum = 0;

    if (k == 1)
        return kadans_sum;

    for (int i = 0; i < n; i++)
    {
        crn_prf_sum += arr[i];
        max_prf_sum = max(max_prf_sum, crn_prf_sum);
    }

    ll total_sum = crn_prf_sum;

    for (int i = n - 1; i >= 0; i--)
    {
        crn_srf_sum += arr[i];
        max_srf_sum = max(max_srf_sum, crn_srf_sum);
    }

    ll ans;
    if (total_sum < 0)
        ans = max(max_prf_sum + max_srf_sum, kadans_sum);
    else
        ans = max(max_prf_sum + max_srf_sum + (total_sum * (k - 2)), kadans_sum);

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        bool allNeg = true;

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (arr[i] >= 0)
                allNeg = false;
        }

        ll ans;
        if (allNeg)
            ans = *max_element(arr, arr + n);
        else
            ans = solve(arr, n, k);

        cout << ans << nl;
    }

    return 0;
}