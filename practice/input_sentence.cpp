#include <iostream>
using namespace std;

int main()
{
    char str[26], str3[34];
    int n;
    cin >> n;
    cin.ignore();
    cin.getline(str, 25);
    cin.getline(str3, 25);

    cout << str << endl;
    cout << str3 << endl;

    return 0;
}