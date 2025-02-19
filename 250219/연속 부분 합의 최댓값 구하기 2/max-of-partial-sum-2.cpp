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
	int ans = -21e8;
	for (int i = 0; i < n; i++) {
		if (sum < 0) {
			sum = arr[i];
		}

		else {
			sum += arr[i];
		}

		ans = max(ans, sum);
	}

	cout << ans;

}