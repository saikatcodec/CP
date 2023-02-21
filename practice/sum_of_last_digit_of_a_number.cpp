#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        cout << "Sum = " << n % 10 + n / 10000 << endl;
    }

    return 0;
}