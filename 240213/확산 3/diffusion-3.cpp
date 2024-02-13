#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

int arr[101][101][101];
bool visited[101][101][101] = {false,};
queue<tuple<int, int, int>> q;
int n, m, h;
int cnt = 0;

bool InRange(int z, int x, int y) {
	return !visited[z][x][y] && arr[z][x][y] == 0 && (0 <= x && x < n && 0 <= y && y < m) && (0 <= z && z < h);
}

void BFS() {
	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };
	int dh[] = { -1,1 };

	while (!q.empty()) {
		int x, y, h;
		tie(h, x, y) = q.front();
		q.pop();

		//너비 연산.

		for (int i = 0; i < 2; i++) {
			int nh = h + dh[i];

			if (InRange(nh, x, y)) {
				visited[nh][x][y] = true;
				arr[nh][x][y] = arr[h][x][y] + 1;
				q.push(make_tuple(nh, x, y));
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(h, nx, ny)) {
				visited[h][nx][ny] = true;
				arr[h][nx][ny] = arr[h][x][y] + 1;
				q.push(make_tuple(h, nx, ny));
			}
		}


	}

	
}

int main() {
	cin >> m >> n >> h;

	for (int t = 0; t < h; t++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[t][i][j];

				if (arr[t][i][j] > 0) {
					q.push(make_tuple(t, i, j));
					visited[t][i][j] = true;
				}
			}
		}
	}

	BFS();
	//cout << "\n";
	
	int ans = 0;
	for (int t = 0; t < h; t++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
			
				if (ans < arr[t][i][j]) {
					ans = arr[t][i][j];
				}

				if (arr[t][i][j] == 0) {
					cout << -1;
					return 0;
				}
			}
		}
	}

	cout << ans - 1;

}