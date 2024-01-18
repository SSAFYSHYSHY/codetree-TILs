#include <iostream>

using namespace std;

int n;
int arr[11];

int main() {
	cin >> n;

	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 4;

	for (int i = 3; i < n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
	}

	cout << arr[n-1];
}