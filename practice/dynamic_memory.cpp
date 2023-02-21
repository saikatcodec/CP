#include <iostream>
using namespace std;

int *returnArr(int n)
{
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i] += 4;
    }

    return arr;
}

int main()
{
    int n;
    cin >> n;

    int *arr;
    arr = returnArr(n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }

    delete[] arr; // free the memory

    return 0;
}