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

        string words[n];
        for (int i = 0; i < n; i++)
            cin >> words[i];

        for (int i = 0; i < n - 1; i++)
        {
            bool sorted = true;

            for (int j = 0; j < n - 1 - i; j++)
            {
                if (words[j][0] > words[j + 1][0])
                {
                    swap(words[j], words[j + 1]);
                    sorted = false;
                }
            }

            if (sorted)
                break;
        }

        for (int i = 0; i < n; i++)
            cout << words[i] << endl;
    }

    return 0;
}