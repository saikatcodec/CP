#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, count = 0;
    cin >> n;
    cin.ignore();

    string str[n];

    for (int i = 0; i < n; i++)
        getline(cin, str[i]);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (str[i] > str[j])
                swap(str[i], str[j]);
        }
    }

    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == str[i + 1])
            count++;
    }

    cout << n - count << endl;

    return 0;
}