#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int arr[11];

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	int sum = 0;
	for (int i = n - 1; i >= 0; i--) {
		sum += (k / arr[i]);

		k = k % arr[i];
	}

	cout << sum;
}