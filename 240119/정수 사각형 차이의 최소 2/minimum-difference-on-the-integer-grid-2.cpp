#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[101][101];
int dp[101][101];

int ans = 21e8;

void Initial() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = 21e8;
		}
	}

	dp[0][0] = arr[0][0];

	for (int i = 1; i < n; i++) {
		dp[i][0] = max(dp[i - 1][0], arr[i][0]);
		dp[0][i] = max(dp[0][i - 1], arr[0][i]);
	}
}

int Calc(int lower) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] < lower) {
				arr[i][j] = 21e8;
			}
		}
	}

	Initial();

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			dp[i][j] = max(min(dp[i - 1][j], dp[i][j - 1]), arr[i][j]);
		}
	}

	return dp[n - 1][n - 1];
}

int main(){
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int lower = 1; lower <= 101; lower++) {
		int upper = Calc(lower);

		if (upper == 21e8) continue;

		ans = min(ans, upper - lower);
	}

	cout << ans;
}