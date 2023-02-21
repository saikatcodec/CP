#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str1[100], str2[100];
    cin >> str1;
    cin >> str2;

    int res = strcasecmp(str1, str2);

    if (res < 0)
        res = -1;
    else if (res > 0)
        res = 1;

    cout << res << endl;

    return 0;
}