#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>

using namespace std;

int n, ans =0;
int arr[501][501];
int dp[501][501];
vector<tuple<int, int, int>> v;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void Initial() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = 1;
		}
	}
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
			v.push_back(make_tuple(arr[i][j], i, j));
		}
	}

	sort(v.begin(), v.end());
	Initial();

	for (int i = 0; i < v.size(); i++) {
		int x, y;
		tie(ignore, x, y) = v[i];

		for (int j = 0; j < 4; j++) {
			int nx = x + dx[j];
			int ny = y + dy[j];

			if (InRange(nx, ny) && arr[nx][ny] > arr[x][y]) {
				dp[nx][ny] = max(dp[nx][ny], dp[x][y] + 1);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans;
}