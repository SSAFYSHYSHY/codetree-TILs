#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>

#include <time.h>

using namespace std;

int arr[501][501];
int new_arr[501][501];
bool visited[501][501] = {false,};
queue<pair<int, int>> q;
int n, m;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };


bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void BFS() {
	while (!q.empty()) {
		pair<int, int> p = q.front();
		int x = p.first;
		int y = p.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == 1) {
				visited[nx][ny] = true;
				new_arr[nx][ny] = new_arr[x][y] + 1;
				q.push(make_pair(nx, ny));
			}

		}
	}
}
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 2) {
				q.push(make_pair(i, j));
				new_arr[i][j] = 0;
				visited[i][j] = true;
			}
		}
	}

	BFS();
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j]) {
				if (arr[i][j] == 0) {
					cout << arr[i][j] << " ";
				}
				else {
					cout << -1 << " ";
				}
			}
			else {
				cout << new_arr[i][j] << " ";
			}
		}
		cout << "\n";
	}
	cout << "\n";
}