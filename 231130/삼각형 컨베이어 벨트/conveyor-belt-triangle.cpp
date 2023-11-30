#include <iostream>

using namespace std;

int arr[201];
int brr[201];
int crr[201];

int n, t;

int main() {
	cin >> n >> t;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> brr[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> crr[i];
	}

	for (int i = 0; i < t; i++) {
		int temp = arr[n - 1];

		for (int j = n - 1; j >= 1; j--) {
			arr[j] = arr[j - 1];
		}

		arr[0] = crr[n - 1];

		int temp2 = brr[n - 1];
		for (int j = n - 1; j >= 1; j--) {
			brr[j] = brr[j - 1];
		}

		brr[0] = temp;

		for (int j = n - 1; j >= 1; j--) {
			crr[j] = crr[j - 1];
		}
		crr[0] = temp2;

	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < n; i++) {
		cout << brr[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < n; i++) {
		cout << crr[i] << " ";
	}
}