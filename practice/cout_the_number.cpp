#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        char line[100000];
        cin.ignore();
        cin.getline(line, 100000);

        int count = 0;
        char *num = strtok(line, " ");
        do
        {
            count++;
            num = strtok(NULL, " ");
        } while (num != NULL);

        cout << count << endl;
    }

    return 0;
}