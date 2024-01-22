#include <iostream>
#include <climits>

using namespace std;

int arr[1001];
int dp[1001][1001];
int n;

void Initial() {
	for (int i = 0; i <= 2 * n; i++) {
		for (int j = 0; j <= 2 * n; j++) {
			dp[i][j] = INT_MIN;
		}
	}

	dp[0][0] = 0;
} 

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[1][1] = arr[1];
	dp[2][0] = arr[2];
	dp[2][1] = arr[1] + arr[2];

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