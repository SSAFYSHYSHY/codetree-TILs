#include <iostream>

using namespace std;

int n;
int arr[100001];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];

		if (sum < 0) {
			sum = 0;
		}
	}

	cout << sum;

}