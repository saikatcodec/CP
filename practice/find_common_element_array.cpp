#include <iostream>
using namespace std;

void common(int n, int arr[])
{
    int com = 1;
    for (int i = 0; i < n; i++)
    {
        com &= arr[i];
    }

    cout << com;
}

int main()
{
    int n;
    cin >> n;

    int arr[] = {1, 4, 5, 4, 6};
    common(5, arr);

    return 0;
}