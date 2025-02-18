#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

long long n, k, l;
long long arr[100001];

bool Calc(long long mid) {
	long long cnt = 0;

	for (long long i = n - mid; i < n; i++) {
		if (arr[i] < mid) {
			cnt += (mid - arr[i]);
		}
	}

	return cnt <= (k * l) && arr[n - mid] + k >= mid;
}

int main() {
	cin >> n >> k >> l;
	for (long long i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	long long le = 1, re = n;
	long long ans = 0;

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