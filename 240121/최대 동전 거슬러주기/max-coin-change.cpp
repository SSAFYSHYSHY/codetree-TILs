#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[101];
int dp[10001];

void Initial() {
	for (int i = 0; i <= m; i++) {
		dp[i] = 21e8;
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
				if (dp[i - arr[j]] == 21e8) continue;

				dp[i] = min(dp[i], dp[i - arr[j]] + 1);
			}
		}
	}

	int ans = dp[m];
	cout << ans + 1;
}