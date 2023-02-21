#include <bits/stdc++.h>
using namespace std;
#include "stackUsingArr.cpp"

int main()
{
    stackUsingArr s(5);

    s.push(34);
    s.push(30);
    s.push(54);
    s.push(40);
    s.push(53);
    s.push(64);

    cout << s.top() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.size() << endl;
    cout << s.pop() << endl;
    cout << s.isEmpty() << endl;
    cout << s.pop() << endl;

    return 0;
}