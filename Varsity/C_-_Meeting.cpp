#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    int a[n], b[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    int maxV = *max_element(a, a + n);
    int minV = *min_element(b, b + n);

    int cnt = 0;
    for (int i = maxV; i <= minV; i++)
    {
        cnt++;
    }

    cout << cnt << nl;

    return 0;
}