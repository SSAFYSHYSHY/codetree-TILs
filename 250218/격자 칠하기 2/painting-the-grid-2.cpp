#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n;
int arr[51][51];
bool visited[51][51] = { false, };
int min_val = 21e9;
int max_val = 0;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void Input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];

			min_val = min(arr[i][j], min_val);
			max_val = max(arr[i][j], max_val);
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

bool Check(int D) {
	int half = (n * n + 1) / 2;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			memset(visited, false, sizeof(visited));

			queue<pair<int, int>> q;
			q.push({ i,j });
			visited[i][j] = true;

			int cnt = 1;

			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();

				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];

					if (InRange(nx, ny) && !visited[nx][ny]) {
						if (abs(arr[nx][ny] - arr[x][y]) <= D) {
							visited[nx][ny] = true;
							q.push({ nx,ny });
							cnt++;
						}
					}
				}
			}

			if (cnt >= half) return true;
		}
	}

	return false;
}

int main() {
	Input();

	//left, d의 최소값.
	int left = 0, right = max_val - min_val;
	int ans = right;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (Check(mid)) {
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	cout << ans;
	
}
