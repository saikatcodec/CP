#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        bool flag = false;
        cin >> n;

        long long arr[n];
        vector<int> pos;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

            if (arr[i] != 0)
            {
                pos.push_back(i);
                if (pos.size() > 1)
                {
                    if (pos[pos.size() - 1] != pos[pos.size() - 2] + 1)
                        flag = true;
                }
            }
        }

        if (pos.size() == 0)
            cout << "0\n";
        else if (flag)
            cout << "2\n";
        else
            cout << "1\n";
    }

    return 0;
}