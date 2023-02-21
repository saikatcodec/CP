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
        int pa, pb, qa, qb;
        cin >> pa >> pb >> qa >> qb;

        if (max(pa, pb) < max(qa, qb))
            cout << "P\n";
        else if (max(pa, pb) > max(qa, qb))
            cout << "Q\n";
        else
            cout << "TIE\n";
    }

    return 0;
}