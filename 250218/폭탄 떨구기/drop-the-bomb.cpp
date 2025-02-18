#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int arr[50001];

int l = 0, r = 1e9;
int ans = 0;

bool Calc(int mid) {
	int cnt = 1;
	int idx = 0;

	for (int i = 0; i < n; i++) {
		if (arr[i] - arr[idx] <= 2 * mid) continue;
		else {
			cnt++;
			idx = i;
		}
	}

	return cnt <= k;
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	while (l <= r) {
		int mid = (l + r) / 2;

		if (Calc(mid)) {
			r = mid - 1;
			ans = mid;
		}
		else {
			l = mid + 1;
		}
	}

	cout << ans;
}