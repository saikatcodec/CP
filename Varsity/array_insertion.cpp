#include <bits/stdc++.h>
using namespace std;

bool insertAtPos(int &n, int arr[], int val, int pos)
{
    if (pos > n + 1 || pos <= 0)
        return false;

    n++;
    for (int i = n; i >= pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = val;

    return true;
}

int main()
{
    int arr[100];

    int n;
    cout << "Enter array size: ";
    cin >> n;

    cout << "Enter array elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int val, pos;
    cout << "Enter value: ";
    cin >> val;

    while (true)
    {

        cout << "Enter position: ";
        cin >> pos;

        if (insertAtPos(n, arr, val, pos))
        {
            cout << "After Inserting value in array:" << endl;
            for (int i = 0; i < n; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
            break;
        }
        else
        {
            cout << "Position is not valid." << endl
                 << "Please try again." << endl;
            continue;
        }
    }

    return 0;
}