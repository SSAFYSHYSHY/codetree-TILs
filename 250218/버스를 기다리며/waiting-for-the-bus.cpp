#include <iostream>
#include <algorithm>

using namespace std;

long long n, m, c;
long long arr[100001];
long long l = 0, r = 1e9, ans = 1e9;

void Input() {
	cin >> n >> m >> c;

	for (long long i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
}

bool Calc(long long mid) {
	long long bus_cnt = 1;
	long long first_person = arr[0];
	long long first_idx = 0;

	for (long long i = 1; i < n; i++) {
		if (arr[i] - first_person > mid || i + 1 - first_idx > c) {
			bus_cnt++;
			first_idx = i;
			first_person = arr[i];
		}
	}

	return (bus_cnt <= m);
}

int main() {
	Input();

	while (l <= r) {
		long long mid = (l + r) / 2;

		if (Calc(mid)) {
			r = mid - 1;
			ans = min(ans, mid);
		}
		else {
			l = mid + 1;
		}
	}

	cout << ans;
}