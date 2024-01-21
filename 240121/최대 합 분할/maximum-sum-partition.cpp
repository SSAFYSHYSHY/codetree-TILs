#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int arr[101];

int dp[101][100001 + 100001];

void Initial() {
	for (int i = 0; i <= n; i++) {
		for (int j = -m; j <= m; j++) {
			dp[i][j + 100000] = INT_MIN;
		}
	}

	dp[0][0 + 100000] = 0;
}

void Calc(int i, int j, int prev_i, int prev_j, int val) {
	if (prev_j < -m || prev_j > m || dp[prev_i][prev_j + 100000] == INT_MIN) {
		return;
	}

	dp[i][j + 100000] = max(dp[i][j + 100000], dp[prev_i][prev_j + 100000] + val);
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		m += arr[i];
	}

	Initial();

	for (int i = 1; i <= n; i++) {
		for (int j = -m; j <= m; j++) {
			//Case 1 . A 그룹에 i 번째 원소 추가.
			Calc(i, j, i - 1, j - arr[i], arr[i]);


			//Case 2 .B 그룹에 i 번째 원소 추가.
			Calc(i, j, i - 1, j + arr[i], 0);


			//Case 3 . C 그룹에 i 번째 원소 추가.
			Calc(i, j, i - 1, j, 0);
		}
	}

	//cout << dp[n][0 + 100000];
}