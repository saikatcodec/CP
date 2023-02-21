#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int reqRun, totalRun, ball;
        double reqRate, curRate;
        cin >> reqRun >> totalRun >> ball;

        reqRate = (reqRun - totalRun + 1) / (ball / 6.00);
        curRate = totalRun / ((300 - ball) / 6.00);

        fixed(cout);
        cout << setprecision(2) << curRate << " " << reqRate << endl;
    }

    return 0;
}