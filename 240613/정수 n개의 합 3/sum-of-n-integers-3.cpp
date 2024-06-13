#include <iostream>
#include <algorithm>

using namespace std;

int n, k, ans = 0;
int arr[501][501];
int prefix[501][501] = { 0, };

int Sum(int x, int y, int x2, int y2) {
	return prefix[x2][y2] - prefix[x - 1][y2] - prefix[x2][y - 1] + prefix[x - 1][y - 1];
}

int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	prefix[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + arr[i][j];
		}
	}

	for (int i = 1; i <= n - k + 1; i++) {
		for (int j = 1; j <= n - k + 1; j++) {
			ans = max(ans, Sum(i, j, i + k - 1, j + k - 1));
		}
	}
	cout << ans;
}