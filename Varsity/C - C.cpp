#include <bits/stdc++.h>
using namespace std;
#define nl "\n"

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int n, d;
    cin >> n >> d;

    vector<tuple<int, int, int>> v;
    tuple<int, int, int> frog;
    int hSum = 0, cnt = 0;

    while (n--)
    {
        int l, w, h;
        cin >> l >> w >> h;

        frog = make_tuple(l, w, h);
        v.push_back(frog);
        hSum += h;
    }

    sort(v.begin(), v.end(), [](tuple<int, int, int> t1, tuple<int, int, int> t2)
         { return get<1>(t1) > get<1>(t2); });

    while (!v.empty())
    {
        frog = *(v.end() - 1);
        v.pop_back();
        hSum -= get<2>(frog);
        int lift = get<0>(frog) + hSum;
        if (lift > d)
            cnt++;
    }

    cout << cnt << nl;

    return 0;
}