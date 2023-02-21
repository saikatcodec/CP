#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        char str[10000];
        cin.getline(str, 10000);

        char *word = strtok(str, " ");
        int count = 0;
        do
        {
            count++;
            word = strtok(NULL, " ");
        } while (word != NULL);

        cout << "Count = " << count << endl;
    }

    return 0;
}