#include <iostream>
using namespace std;

bool isSort(int n, int arr[])
{
    if (n == 1)
        return true;

    bool flag = isSort(n - 1, arr + 1);

    if (arr[0] <= arr[1] && flag)
        return true;
    else
        return false;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    bool ans = isSort(n, arr);

    if (ans)
        cout << "Array is sorted" << endl;
    else
        cout << "Array is not sorted" << endl;

    return 0;
}