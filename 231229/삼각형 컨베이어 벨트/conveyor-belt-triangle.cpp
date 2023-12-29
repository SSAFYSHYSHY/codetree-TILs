#include <iostream>

using namespace std;

int n, t;
int arr[201];
int brr[201];
int crr[201];

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

	while (t--) {
		int temp = arr[n - 1];

		for (int i = n - 1; i > 0; i--) {
			arr[i] = arr[i - 1];
		}
		arr[0] = crr[n - 1];
		int temp2 = brr[n - 1];

		for (int i = n - 1; i > 0; i--) {
			brr[i] = brr[i - 1];
		}
		brr[0] = temp;

		for (int i = n - 1; i > 0; i--) {
			crr[i] = crr[i - 1];
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