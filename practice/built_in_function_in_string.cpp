#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string str, newStr = "Joy";
    getline(cin, str);

    cout << "Length of string is " << str.length() << endl;
    cout << "Find 'a' in the string " << str.find('a') << endl;
    cout << "String compare with my name " << str.compare(newStr) << endl;

    string num = "373";
    sort(num.begin(), num.end(), greater<int>());
    cout << "Find the greater number from the string " << num;

    return 0;
}