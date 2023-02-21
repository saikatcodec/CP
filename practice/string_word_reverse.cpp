#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();

    while (t--)
    {
        string reversStr = "";
        char str[1000];
        cin.getline(str, 1000);

        char *word = strtok(str, " ");
        do
        {
            reversStr += string(strrev(word));
            word = strtok(NULL, " ");
            if (word != NULL)
                reversStr += " ";
        } while (word != NULL);

        cout << reversStr << endl;
    }

    return 0;
}