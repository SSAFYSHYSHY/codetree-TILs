#include <iostream>
#include <climits>

using namespace std;

int n, m;
int weight[101];
int value[101];
int dp[10001];

void Initial() {
	for (int i = 0; i <= m; i++) {
		dp[i] = INT_MIN;
	}

	dp[0] = 0;
}


int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> weight[i] >> value[i];
	}

	Initial();

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (i >= weight[j]) {
				if (dp[i - weight[j]] == INT_MIN) continue;

				dp[i] = max(dp[i], dp[i - weight[j]] + value[j]);
			}
		}
	}


	int ans = 0;
	for (int j = 0; j <= m; j++) {
		ans = max(ans, dp[j]);
	}
	cout << ans;
}