#include <iostream>
#include <queue>

using namespace std;

int n, k, cnt = 0;
int arr[101][101];
queue<pair<int, int>> q;
bool visited[101][101];

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y) {
	return InRange(x, y) && !arr[x][y] && !visited[x][y];
}

void BFS() {
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

			if (CanGo(nx, ny)) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}

	}
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;

		x -= 1;
		y -= 1;

		q.push(make_pair(x, y));
		visited[x][y] = true;
	}

	BFS();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) {
				cnt++;
			}
		}
	}

	cout << cnt;
}