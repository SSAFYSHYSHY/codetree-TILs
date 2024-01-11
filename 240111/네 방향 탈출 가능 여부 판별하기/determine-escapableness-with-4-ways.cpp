#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[101][101];
bool visited[101][101];
queue<pair<int, int>> q;

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

bool CanGo(int x, int y) {
	if (!InRange(x, y)) {
		return false;
	}
	if (visited[x][y] || arr[x][y] == 0) {
		return false;
	}

	return true;
}

void BFS(int x, int y) {
	while (!q.empty()) {
		pair<int, int> curr = q.front();
		int x = curr.first;
		int y = curr.second;
		q.pop();

		int dx[] = {-1,1,0,0};
		int dy[] = {0,0,-1,1};

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (CanGo(nx, ny)) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
				BFS(nx, ny);
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	q.push(make_pair(0, 0));
	visited[0][0] = true;
	BFS(0, 0);

	cout << visited[n-1][m-1];
}