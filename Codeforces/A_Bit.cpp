#include <iostream>
using namespace std;

int main()
{
    int n, x = 0;
    cin >> n;

    while (n--)
    {
        string stat;
        cin >> stat;

        if (stat == "X++")
            x++;
        else if (stat == "X--")
            x--;
        else if (stat == "++X")
            ++x;
        else if (stat == "--X")
            --x;
    }

    cout << x << endl;

    return 0;
}