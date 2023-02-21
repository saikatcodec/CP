#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int fNum, sNum;
        cin >> fNum >> sNum;

        int gcd = __gcd(fNum, sNum);
        int lcm = (fNum * sNum) / gcd;
        cout << "LCM = " << lcm << endl;
    }

    return 0;
}