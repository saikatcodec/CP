#include <bits/stdc++.h>
using namespace std;

bool deleteAtPos(int &n, int arr[], int pos)
{
    if (pos > n)
        return false;

    n--;
    for (int i = pos - 1; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }

    return true;
}

int main()
{
    int n;
    cout << "Array size: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int pos;
    cout << "Enter position: ";
    cin >> pos;

    cout << "Before deleting the value" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    if (deleteAtPos(n, arr, pos))
    {
        cout << "After deleting the value" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else
        cout << "Position is not found" << endl;

    return 0;
}