#include <iostream>
using namespace std;

int main()
{
    int matches[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    int t;
    cin >> t;

    while (t--)
    {
        int a, b, sum, matchesSum = 0;
        cin >> a >> b;

        sum = a + b;

        while (1)
        {
            int digit = sum % 10;
            sum /= 10;
            matchesSum += matches[digit];
            if (sum == 0)
                break;
        }

        cout << matchesSum << endl;
    }

    return 0;
}