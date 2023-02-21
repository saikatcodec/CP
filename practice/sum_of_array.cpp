#include <bits/stdc++.h>
using namespace std;

int sumA(int arr[], int size) {
	if (size == 0)
		return 0;
	
	return arr[0] + sumA(arr + 1, size - 1);
}

int main() {
 	int n;
 	cin >> n;
 	
 	int arr[n];
 	for (int i = 0; i < n; i++)
 		cin >> arr[i];
 		
 	int result = sumA(arr, n);
 	cout << result << endl;

	return 0;
}
