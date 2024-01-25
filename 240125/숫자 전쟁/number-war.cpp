#include <iostream>

using namespace std;

int n;
int arr[1005], brr[1005];
int dp[1005][1005];

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> brr[i];
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 0;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (dp[i][j] == -1) continue;

			if (i < n && arr[i + 1] < brr[j + 1]) {
				dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
			}
			
			if (j < n && arr[i + 1] > brr[j + 1]) {
				dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + brr[j+1]);
			}

			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j]);
		}
	}

	int ans = 0;
	for (int i = 0; i <= n; i++) {
		ans = max(ans, dp[i][n]);
		ans = max(ans, dp[n][i]);
	}
	cout << ans;

}