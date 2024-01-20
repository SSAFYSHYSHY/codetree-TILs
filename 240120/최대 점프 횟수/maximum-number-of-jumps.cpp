#include <iostream>
#include <climits>

using namespace std;

int arr[1001];
int dp[1001];
int n;

void Initial() {
	for (int i = 0; i < n; i++) {
		dp[i] = INT_MIN;
	}

	dp[0] = 0;
}

int main() {
	cin >> n;

	Initial();

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (dp[j] == INT_MIN) continue;

			if (j + arr[j] >= i) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans;
}