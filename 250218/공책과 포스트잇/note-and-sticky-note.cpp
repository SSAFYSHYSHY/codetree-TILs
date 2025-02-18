#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, k, l;
int arr[100001];

bool Calc(int mid) {
	int cnt = 0;

	for (int i = n - mid; i < n; i++) {
		if (arr[i] < mid) {
			cnt += (mid - arr[i]);
		}
	}

	return cnt <= (k * l) && arr[n - mid] + k >= mid;
}

int main() {
	cin >> n >> k >> l;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int le = 1, re = n;
	int ans = 0;

	while (le <= re) {
		int mid = (le + re) / 2;

		if (Calc(mid)) {
			le = mid + 1;
			ans = max(ans, mid);
		}
		else {
			re = mid - 1;
		}
	}

	cout << ans;

}