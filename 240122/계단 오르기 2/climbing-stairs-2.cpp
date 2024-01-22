#include <iostream>
#include <climits>

using namespace std;

int arr[1005];
int dp[1005][5];
int n;

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[1][1] = arr[1];
	dp[2][0] = arr[2];
	dp[2][2] = arr[1] + arr[2];

	//최대 가치를 출력.
	//i 번재 위치에 도착했을때, 정확히 j 번 1계단 올랐을때의 최대 가치.
	for (int i = 3; i <= n; i++) {
		
		for (int j = 0; j <= 3; j++) {
			dp[i][j] = max(dp[i][j], dp[i - 2][j] + arr[i]);

			if (j) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + arr[i]);
			}
		}
	}

	int ans = 0;
	for (int j = 0; j <= 3; j++) {
		ans = max(ans, dp[n][j]);
	}
	cout << ans;
}