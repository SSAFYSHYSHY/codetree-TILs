#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[101];
int dp[10001];

void Initial() {
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		
	}

	for (int i = 1; i <= m; i++) {
		dp[i] = 21e8;
	}
	dp[0] = 0;
}

int main() {
	cin >> n >> m;

	Initial();

	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {
			if (j >= arr[i]) {
				if (dp[j - arr[i]] == 21e8) continue;

				dp[j] = min(dp[j], dp[j - arr[i]] + 1);
			}

		}
	}

	int ans = dp[m];
	if (ans == 21e8) {
		cout << -1;
		return 0;
	}

	cout << ans;
}