#include <bits/stdc++.h>
using namespace std;

void replaceStr(char str[], int ind) {
    if (str[ind] == '\0') {
        return;
    }

    if (str[ind] == 'p' and str[ind + 1] == 'i') {
        for (int i = strlen(str) + 2; i >= ind + 4; i--) {
            str[i] = str[i - 2];
        }
        
        str[ind] = '3';
        str[ind + 1] = '.';
        str[ind + 2] = '1';
        str[ind + 3] = '4';
    }
    replaceStr(str, ind + 1);
}

int main() {
    char str[200];
    cin >> str;

    replaceStr(str, 0);

    cout << str << endl;

    return 0;
}