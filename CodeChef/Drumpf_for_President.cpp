#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k, cnt = 0;
        cin >> n >> k;

        map<int, int> person;
        vector<int> track;

        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            if (i + 1 == a)
                track.push_back(a);

            person[a]++;
        }

        for (auto it : person)
        {
            if (!binary_search(track.begin(), track.end(), it.first) && it.second >= k)
                cnt++;
        }

        cout << cnt << "\n";
    }

    return 0;
}