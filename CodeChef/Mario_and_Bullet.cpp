#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int x, y, z;
        cin >> x >> y >> z;

        int time = z - (y / x);

        if (time <= 0)
            time = 0;

        cout << time << endl;
    }

    return 0;
}