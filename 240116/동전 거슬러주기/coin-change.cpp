#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;

int ans = 0;
int dp[10001];
int arr[101];

void Initial() {
	for (int i = 0; i <=m ; i++) {
		dp[i] = INT_MAX;
	}
	dp[0] = 0;
}

int main() {

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	Initial();

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (i >= arr[j]) {
				if (dp[i - arr[j]] == INT_MAX) {
					continue;
				}

				dp[i] = min(dp[i], dp[i - arr[j]] + 1);
			}
		}
	}
	ans = dp[m];

	/*for (int i = 0; i < m; i++) {
		cout << dp[i] << " ";
	}*/

	if (ans == INT_MAX) {
		cout << -1;
		return 0;
	}
	cout << ans;
}