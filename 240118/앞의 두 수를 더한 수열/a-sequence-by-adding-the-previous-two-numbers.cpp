#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[21];

int main() {
	cin >> n;

	arr[0] = 0;
	arr[1] = 1;

	for (int i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}

	cout << arr[n];

}