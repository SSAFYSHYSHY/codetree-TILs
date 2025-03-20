#include <iostream>
#include <cmath>
#define MAX_N 100

using namespace std;

int n, L;
int grid[110][110];
int arr[110];
int ramp_cnt[110];

bool AllSame(int l, int r) {
	for (int i = l; i <= r; i++) {
		if (arr[i] != arr[l]) {
			return false;
		}
	}

	return true;
}

bool Calc() {
	for (int i = 0; i < n - 1; i++) {
		if (abs(arr[i] - arr[i + 1]) >= 2) {
			return false;
		}
	}

	for (int i = 0; i < n; i++) {
		ramp_cnt[i] = 0;
	}

	for (int i = 0; i < n - 1; i++) {
		if (arr[i] == arr[i + 1] + 1) {
			if (i + L >= n) return false;
			if (!AllSame(i + 1, i + L)) return false;
			for (int j = i + 1; j <= i + L; j++) {
				ramp_cnt[j]++;
			}
		}
	}

	for (int i = 1; i < n; i++) {
		if (arr[i] == arr[i - 1] + 1) {
			if (i - L < 0) return false;
			if (!AllSame(i - L, i - 1)) return false;
			for (int j = i - L; j <= i - 1; j++) {
				ramp_cnt[j]++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (ramp_cnt[i] >= 2) return false;
	}
	return true;
}

int main() {
	int max_gold = 0, ans = 0;

	cin >> n >> L;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[j] = grid[i][j];
		}

		if (Calc()) {
			ans++;
		}
	}

	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			arr[i] = grid[i][j];
		}

		if (Calc()) {
			ans++;
		}
	}

	cout << ans;
}