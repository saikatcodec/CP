#include <bits/stdc++.h>
using namespace std;

int noWay(int n) {
    if (n <= 3) {
        return 1;
    }

    return noWay(n - 1) + noWay(n - 4);
}

int main() {
    int n;
    cout << "The wall size is 4 X N, and you can place\
     the bricks of size 1 X 4 or 4 X 1"
         << endl;
    cout << "Enter N: ";
    cin >> n;

    cout << "No of ways to put the tiles or bricks in the wall: ";
    cout << noWay(n) << endl;

    return 0;
}