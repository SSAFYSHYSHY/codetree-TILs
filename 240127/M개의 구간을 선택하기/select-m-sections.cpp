#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

enum State {
	NOT_b,
	b
};

int n, m;
int arr[501];
int dp[501][251][2];

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			dp[i][j][NOT_b] = dp[i][j][b] = -500000;
		}
	}

	for (int i = 0; i <= n; i++) {
		dp[i][0][NOT_b] = 0;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j][b] = max(dp[i - 1][j - 1][NOT_b] + arr[i], dp[i - 1][j][b] + arr[i]);

			dp[i][j][NOT_b] = max(dp[i - 1][j][NOT_b], dp[i - 1][j][b]);
		}
	}

	cout << max(dp[n][m][NOT_b], dp[n][m][b]);
}