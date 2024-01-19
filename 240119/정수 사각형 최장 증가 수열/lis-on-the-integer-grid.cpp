#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[501][501];
int dp[501][501];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

int Calc(int x, int y, int cnt) {
	if (dp[x][y]) {
		return dp[x][y];
	}
	
	int max_cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (InRange(nx, ny) && arr[nx][ny] > arr[x][y]) {
			max_cnt = max(max_cnt, cnt + Calc(nx, ny, cnt));
		}
	}

	dp[x][y] = max_cnt;
	return max_cnt;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!dp[i][j]) {
				Calc(i, j, 1);
			}
		}
	}
	
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ans < dp[i][j]) {
				ans = dp[i][j];
			}
		}
	}

	cout << ans + 1;
}