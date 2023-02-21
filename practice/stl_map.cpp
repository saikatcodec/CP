#include <bits/stdc++.h>
using namespace std;

struct node
{
    int value = -1;
};

int main()
{
    map<int, int> myMap;
    // myMap[1] = 4;
    // myMap[2] = 5;
    // myMap[3] = 3;
    // myMap[5] = 1;
    // myMap[7] = 9;

    for (int i = 0; i < 4; i++)
    {
        int a;
        cin >> a;
        myMap[a]++;
    }

    for (auto it : myMap)
        cout << it.first << "  " << it.second << "\n";

    return 0;
}