#include <iostream>
#include <algorithm>

using namespace std;

int n, m, c;
int arr[100001];
int l = 0, r = 1e9, ans = 0;

void Input() {
	cin >> n >> m >> c;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);
}

bool Calc(int mid) {
	int bus_cnt = 1;
	int last_person = arr[0];

	for (int i = 1; i < n; i++) {
		if (arr[i] - last_person <= mid && bus_cnt < c) {
			continue;
		}

		else {
			bus_cnt++;
			last_person -= arr[i];
		}

		if (bus_cnt > m) return false;
	}

	return true;
}

int main() {
	Input();

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

	cout << ans + 1;
}