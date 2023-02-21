#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define llu long long unsigned
#define pi 3.14159265359
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
 
        if (l1 >= l2 && l1 <= r2)
            cout << l1;
        else if (r1 >= l2 && r1 <= r2)
            cout << l2;
 
        else if (l2 >= l1 && l2 <= r1)
            cout << l2;
        else if (r2 >= l1 && r2 <= r1)
            cout << r2;
 
        else if (l1 > r2 && r1 > r2)
            cout << l1 + l2;
        else if (l1 < l2 && r1 < l2)
            cout << l1 + l2;
 
        printf("\n");
    }
}