#include <iostream>

using namespace std;

int n, k;
int arr[11];

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int ans = 0, cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		ans += (k / arr[i]);
		cnt = k / arr[i];
		k -= (arr[i] * cnt);
	}

	cout << ans;
}