#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int err[101];
int rrr[101];
int dp[101][10001];
int n, m, t;

void Initial() {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= t; j++) {
			dp[i][j] = INT_MIN;
		}
	}

	dp[0][0] = 0;
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> err[i] >> rrr[i];
	}
	for (int i = 1; i <= n; i++) {
		t += rrr[i];
	}

	Initial();


	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= t; j++) {
			if (j - rrr[i] >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - rrr[i]] + err[i]);
			}

			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}

	int ans = INT_MAX;

	for (int j = 0; j <= t; j++) {
		if (dp[n][j] >= m) {
			ans = min(ans, j);
		}
	}

	if (ans == INT_MAX) {
		ans = -1;
	}

	//cout << ans;

}