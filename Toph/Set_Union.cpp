#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    set<int> s1;
    set<int>::iterator it;

    for (int i = 0; i < n; i++)
    {
        int ele;
        cin >> ele;
        s1.insert(ele);
    }
    for (int i = 0; i < m; i++)
    {
        int ele;
        cin >> ele;
        s1.insert(ele);
    }

    for (it = s1.begin(); it != s1.end(); it++)
    {
        if (it == s1.end())
            cout << *it;
        cout << *it << " ";
    }

    cout << nl;

    return 0;
}