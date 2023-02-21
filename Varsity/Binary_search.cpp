#include <bits/stdc++.h>
using namespace std;

bool bSearch(int n, int arr[], int key)
{
    int fIndex = 0;
    int lIndex = n;

    while (fIndex <= lIndex)
    {
        int mid = (fIndex + lIndex) / 2;

        if (arr[mid] == key)
            return true;
        else if (arr[mid] > key)
            lIndex = mid - 1;

        else if (arr[mid] < key)
            fIndex = mid + 1;
    }

    return false;
}

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];
    cout << "Enter array element: " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int key;
    cout << "What value you want to search? ";
    cin >> key;

    if (bSearch(n, arr, key))
        cout << "Value found in the list" << endl;

    else
        cout << "Value is not present" << endl;

    return 0;
}