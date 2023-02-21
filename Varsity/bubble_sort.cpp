#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int n, int arr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

int main()
{
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n];
    cout << "Enter array element: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Sort the array
    bubble_sort(n, arr);

    cout << "After sorting:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}