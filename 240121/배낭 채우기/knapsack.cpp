#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int dp[10001];
int weight[101];
int value[101];
int n, m;

void Initial() {
	for (int j = 0; j <= m; j++) {
		dp[j] = INT_MIN;
	}
	dp[0] = 0;
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> weight[i] >> value[i];
	}

	Initial();

	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= weight[i]; j--) {
			dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
		}
	}

	int ans = 0;
	for (int j = 0; j <= m; j++) {
		ans = max(ans, dp[j]);
	}
	cout << ans;
}