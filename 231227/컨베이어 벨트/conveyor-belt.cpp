#include <iostream>

using namespace std;

int n, t;
int arr[201];
int brr[201];

int main() {
	cin >> n >> t;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> brr[i];
	}

	while (t--) {
		int temp1 = arr[n - 1];

		for (int i = n - 1; i > 0; i--) {
			arr[i] = arr[i - 1];
		}
		arr[0] = brr[n-1];

		for (int i = n-1; i > 0; i--) {
			brr[i] = brr[i - 1];
		}
		brr[0] = temp1;
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < n; i++) {
		cout << brr[i] << " ";
	}

}