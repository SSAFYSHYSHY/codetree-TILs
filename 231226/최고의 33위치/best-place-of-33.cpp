#include <iostream>

using namespace std;

int n, ans = 0;
int arr[21][21];

int Calc(int x, int y) {
	int cnt = 0;
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			cnt += arr[i][j];
		}
	}

	return cnt;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n - 2; i++) {
		for (int j = 0; j < n - 2; j++) {
			int cnt = Calc(i, j);

			ans = max(ans, cnt);
		}
	}
	cout << ans;
}