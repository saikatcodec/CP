#include <bits/stdc++.h>
using namespace std;

int *sum_of_arr(int n)
{
    int sum = 0;
    int *arr = new int[n]; // create dynamic memory
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    return arr;
}

int main()
{
    int n;
    cin >> n;

    int *arr = sum_of_arr(n);
    for (int i = 0; i < n; i++)
        cout << arr[i] + 1 << endl;

    delete[] arr;

    return 0;
}