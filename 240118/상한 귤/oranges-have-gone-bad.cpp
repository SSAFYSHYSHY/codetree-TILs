#include <iostream>
#include <queue>

using namespace std;

int n, k;
int arr[101][101];
int new_arr[101][101];
bool visited[101][101];

queue<pair<int, int>> q;

void Push(int x, int y, int num) {
	visited[x][y] = true;
	new_arr[x][y] = num;
	q.push(make_pair(x, y));
}
bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
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

			if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] != 0) {
				Push(nx, ny, new_arr[x][y] + 1);
			}
		}

	}
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) {
				new_arr[i][j] = -1;
			}

			if (arr[i][j] == 2) {
				Push(i, j, 0);
			}
		}
	}

	BFS();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			if (new_arr[i][j] == 0 && arr[i][j] == 1) {
				cout << -2;
			}
			else {
				cout << new_arr[i][j] << " ";
			}
		}

		cout << "\n";
	}
}