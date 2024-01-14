#include <iostream>
#include <algorithm>

using namespace std;

int n, m, c;
int arr[11][11];

int brr[6];

int ans, max_val = 0;

void Calc4(int curr_idx, int curr_w, int curr_val) {
	if (curr_idx == m) {
		if (curr_w <= c) {
			max_val = max(max_val, curr_val);
		}

		return;
	}

	Calc4(curr_idx + 1, curr_w, curr_val);
	Calc4(curr_idx + 1, curr_w + brr[curr_idx], curr_val + brr[curr_idx] * brr[curr_idx]);
}

int Calc2(int sx, int sy) {
	for (int i = sy; i <= sy + m - 1; i++) {
		brr[i - sy] = arr[sx][i];
	}

	max_val = 0;
	Calc4(0, 0, 0);

	return max_val;
}

bool Calc3(int a, int b, int c, int d) {
	return !(b < c || d < a);
}

bool Calc(int sx, int sy, int sx1, int sy1) {
	if (sy + m - 1 >= n || sy1 + m - 1 >= n) {
		return false;
	}

	if (sx != sx1) {
		return true;
	}

	if (Calc3(sy, sy + m - 1, sy1, sy1 + m - 1)) {
		return false;
	}

	return true;
}

int main() {
	cin >> n >> m >> c;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int sx = 0; sx < n; sx++) {
		for (int sy = 0; sy < n; sy++) {
			for (int sx1 = 0; sx1 < n; sx1++) {
				for (int sy1 = 0; sy1 < n; sy1++) {
					if (Calc(sx, sy, sx1, sy1)) {
						ans = max(ans, Calc2(sx, sy) + Calc2(sx1, sy1));
					}
				}
			}
		}
	}

	cout << ans;
}