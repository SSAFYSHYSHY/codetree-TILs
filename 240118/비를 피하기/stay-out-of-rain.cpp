#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, h, m;
int arr[101][101];
queue<pair<int, int>> q;
bool visited[101][101];
int new_arr[101][101];
int ans[101][101];

void Initial() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
			new_arr[i][j] = 0;
		}
	}

	if (!q.empty()) {
		for (int i = 0; i < q.size(); i++) {
			q.pop();
		}
	}
}

void Push(int x, int y, int num) {
	visited[x][y] = true;
	q.push(make_pair(x, y));
	new_arr[x][y] = num;
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
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

			if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] != 1) {
				Push(nx, ny, new_arr[x][y] + 1);
			}
		}
	}

	int mini = 21e8;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 3 && new_arr[i][j]) {
				mini = min(mini, new_arr[i][j]);
			}
		}
	}

	return mini == 21e8 ? -1 : mini;
}

int main() {
	cin >> n >> h >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Initial();
			
			if (arr[i][j] == 2) {
				Push(i, j, 0);
				int a = BFS();

				ans[i][j] = a;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}