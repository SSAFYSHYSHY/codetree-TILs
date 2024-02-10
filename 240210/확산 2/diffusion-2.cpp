#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[1001][1001];
queue<pair<int, int>> q;
bool visited[1001][1001] = {false,};

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void BFS() {
	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };

	while (!q.empty()) {
		pair<int, int> p = q.front();
		int currx = p.first;
		int curry = p.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = currx + dx[i];
			int ny = curry + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == 0) {
				visited[nx][ny] = true;
				arr[nx][ny] = arr[currx][curry] + 1;
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
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				q.push(make_pair(i, j));
				visited[i][j] = true;
			}
		}
	}
	BFS();

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			//cout << arr[i][j] << " ";

			if (arr[i][j] > ans) {
				ans = arr[i][j];
			}

			if (arr[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
		//cout << "\n";
	}

	cout << ans - 1;
}