#include <bits/stdc++.h>
using namespace std;

void insertAtPos(int &n, int arr[], int val, int pos)
{
    if (pos > n + 1)
        return;
    n++;

    for (int i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = val;
}

int main()
{
    int arr[100] = {0};

    int n;
    cout << "Enter array size: " << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int val, pos;
    cout << "Enter value: ";
    cin >> val;

    cout << "Enter position: ";
    cin >> pos;

    cout << "Before Inserting value: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    insertAtPos(n, arr, val, pos);

    cout << "After inserting value:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}