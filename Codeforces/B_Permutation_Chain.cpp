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
        cin >> n;

        vector<vector<int>> v;
        vector<int> sv;
        vector<int>::iterator it;

        for (int i = 1; i <= n; i++)
        {
            sv.push_back(i);
        }
        v.push_back(sv);

        for (int i = 1; i <= n - 1; i++)
        {
            sv = *(v.end() - 1);
            it = sv.begin() + (i - 1);
            iter_swap(it, it + 1);
            v.push_back(sv);
        }

        cout << v.size() << endl;
        for (auto eles : v)
        {
            for (auto ele : eles)
            {
                cout << ele << " ";
            }
            cout << endl;
        }
    }

    return 0;
}