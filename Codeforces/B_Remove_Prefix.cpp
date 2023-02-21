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

        vector<int> v;
        map<int, int> frq;
        set<int> st;

        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            v.push_back(a);
            frq[a]++;
        }

        vector<int>::reverse_iterator it = v.rbegin();
        for (; it != v.rend(); it++)
        {
            if (st.find(*it) != st.end())
                break;
            st.insert(*it);
        }

        cout << n - st.size() << endl;
    }

    return 0;
}