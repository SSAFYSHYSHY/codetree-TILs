#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, cnt =0;
int arr[101][101];
int num[101][101];
queue<pair<int, int>> q;
bool visited[101][101] = {false,};

bool InRange(int x, int y) {
	return (1 <= x && x <= n && 1 <= y && y <= m) && !visited[x][y] && arr[x][y] != 0;
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

			if (InRange(nx, ny)) {
				num[nx][ny] = num[x][y] + 1;
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	num[1][1] = 1;
	visited[1][1] = true;
	q.push(make_pair(1, 1));
	BFS();
	
	cout << num[n][m];
}