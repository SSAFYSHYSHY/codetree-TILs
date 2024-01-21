#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[101];
int dp[10001];

void Initial() {
	for (int i = 0; i <= m; i++) {
		dp[i] = 0;
	}
	dp[0] = 10000;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	Initial();

	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < n; j++) {
			if (i >= arr[j]) {
				if (dp[i - arr[j]] == 0) continue;

				dp[i] = max(dp[i], dp[i - arr[j]] + 1);
			}
		}
	}

	int ans = dp[m] - 10000;

	if (ans == -10000) {
		cout << -1;
		return 0;
	}
	cout << ans;
}