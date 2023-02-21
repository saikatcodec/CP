#include <bits/stdc++.h>
using namespace std;

int sub(char *str, int n)
{
    int count;

    if (n == 0)
        return 0;

    count = sub(str + 2, n - 2);
    if ((str[0] != str[1]))
        count++;

    return count;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        char str[n + 1];
        cin.ignore();
        cin.getline(str, n + 1);

        int ans = sub(str, n);
        cout << ans << endl;
    }

    return 0;
}