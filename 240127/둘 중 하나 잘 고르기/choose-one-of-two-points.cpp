#include <iostream>
#include <climits>

using namespace std;

int arr[202];
int brr[202];
int n;
int dp[202][101];
bool visited[202][101];

int Calc(int idx, int num) {
	if (idx == 0 && num > 0 || num < 0) return INT_MIN;

	if (idx == 0) {
		return 0;
	}

	if (visited[idx][num]) {
		return dp[idx][num];
	}

	visited[idx][num] = true;

	dp[idx][num] = max(Calc(idx - 1, num) + brr[idx], Calc(idx - 1, num - 1) + arr[idx]);

	return dp[idx][num];
}

int main() {
	cin >> n;

	for (int i = 1; i <= 2*n; i++) {
		cin >> arr[i] >> brr[i];
	}

	for (int i = 0; i <= 2*n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = INT_MIN;
		}
	}

	int ans = Calc( 2*n, n);

	cout << ans;
}