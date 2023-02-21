#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int num = n;
        int sum = 0, temp;

        while (n != 0)
        {
            temp = n % 10;
            sum += pow(temp, 3);
            n /= 10;
        }

        if (sum == num)
            cout << num << " is an armstrong number!" << endl;
        else
            cout << num << " is not an armstrong number!" << endl;
    }

    return 0;
}