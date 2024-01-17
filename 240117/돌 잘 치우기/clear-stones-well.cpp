#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, m, k, ans = 0;
int arr[101][101];
bool visited[101][101];
queue<pair<int, int>> q;

void Initial() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}
}

bool InRange(int x, int y) {
	return !visited[x][y] && (0 <= x && x < n && 0 <= y && y < n) && (arr[x][y] != 1);
}

int BFS() {
	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };

	while (!q.empty()) {
		pair<int, int> p = q.front();
		int x = p.first;
		int y = p.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny)) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) cnt++;
		}
	}

	return cnt;
}

void Calc(int num) {
	if (num == m) {
		ans = max(ans, BFS());
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j]) {
				arr[i][j] = 0;
				Calc(num + 1);
				arr[i][j] = 1;
			}
		}
	}
}

int main() {
	cin >> n >> k >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		Initial();

		int x, y;
		cin >> x >> y;
		x -= 1, y -= 1;

		q.push(make_pair(x, y));
		visited[x][y] = true;

		Calc(0);
	}

	cout << ans;
}