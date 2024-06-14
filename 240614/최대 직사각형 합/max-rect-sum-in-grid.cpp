#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int arr[301][301];
int prefix[301][301];
int dp[301];
int n, ans = 0;

int Sum(int x1, int y1, int x2, int y2) {
	return prefix[x2][y2] - prefix[x1 - 1][y2] - prefix[x2][y1-1] + prefix[x1 - 1][y1 - 1];
}

int Area(int x1, int x2) {
	for (int y = 1; y <= n; y++) {
		int value = Sum(x1, y, x2, y);
		dp[y] = max(value, dp[y - 1] + value);
	}

	int max_area = INT_MIN;
	for (int y = 1; y <= n; y++) {
		max_area = max(max_area, dp[y]);
	}

	return max_area;
}

int main() {
	cin >> n;

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

	int ans = INT_MIN;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			ans = max(ans, Area(i, j));
		}
	}

	cout << ans;
}