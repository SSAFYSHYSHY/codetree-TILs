#include <iostream>
#include <algorithm>

using namespace std;

int arr[51][51];
int dp[51][51];
int n, m;

void Initial() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			dp[i][j] = 1;
		}
	}
}

int main() {
	cin >> n >> m;

	Initial();

	for (int x = 1; x < n; x++) {
		for (int y = 1; y < n; y++) {
			for (int i = 0; i < x; i++) {
				for (int j = 0; j < y; j++) {
					if (arr[x][y] > arr[i][j]) {
						dp[x][y] = max(dp[x][y], dp[i][j] + 1);
					}
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans;
}