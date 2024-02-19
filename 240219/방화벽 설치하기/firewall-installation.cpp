#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

queue<pair<int, int>> q;
int arr[9][9];
int new_arr[9][9];
bool visited[9][9] = { false, };
bool visited_bfs[9][9] = { false, };
int n, m, ans = 0;

void Initial() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited_bfs[i][j] = false;
			new_arr[i][j] = arr[i][j];
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
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

			if (InRange(nx, ny) && !visited_bfs[nx][ny] && new_arr[nx][ny] == 0) {
				q.push(make_pair(nx, ny));
				visited_bfs[nx][ny] = true;
				new_arr[nx][ny] = 2;
			}
		}
	}
}


int Calc2() {
	Initial();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (new_arr[i][j] == 2 && !visited_bfs[i][j]) {
				q.push(make_pair(i, j));
				visited[i][j] = true;
				BFS();
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (new_arr[i][j] == 0) {
				cnt++;
			}
		}
	}

	return cnt;
}

void Calc(int num) {
	if (num == 3) {
		ans = max(ans, Calc2());
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && arr[i][j] == 0) {
				visited[i][j] = true;
				arr[i][j] = 1;
				Calc(num + 1);
				arr[i][j] = 0;
				visited[i][j] = false;
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

	Calc(0);

	cout << ans;
}