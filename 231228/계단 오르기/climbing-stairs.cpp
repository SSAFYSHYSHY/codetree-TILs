#include <iostream>

using namespace std;

int arr[1001] = {0,};
int n;

int main() {
	cin >> n;

	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 1;

	for (int i = 5; i <= n; i++) {
		arr[i] = (arr[i - 3] + arr[i - 2]) % 10007;
	}

	cout << arr[n];
}