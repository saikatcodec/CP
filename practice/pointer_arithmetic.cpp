#include <bits/stdc++.h>
using namespace std;

int main()
{

    int a[6];

    for (int i = 0; i < 6; i++)
    {
        cin >> *(a + i);
    }

    cout << "Printing value" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << *(a + i) << endl;
    }

    return 0;
}