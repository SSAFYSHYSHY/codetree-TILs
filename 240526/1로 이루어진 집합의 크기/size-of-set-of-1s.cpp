#include <iostream>
#include <queue>

using namespace std;

int arr[501][501];
bool visited[501][501] = {false,};
queue<pair<int, int>> q;
int ans = 0;
int n, m;


int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void Initial() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int BFS() {
	int cnt = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == 1) {
				cnt++;
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}

	return cnt;
}

void Calc() {
	//초기화.
	Initial();

	//1인 것들을 BFS
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1 && !visited[i][j]) {
				visited[i][j] = true;
				q.push(make_pair(i, j));

				ans = max(ans, BFS());
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
			bool flag = false;

			//초기화.
			if (arr[i][j] == 0 && !flag) {
				arr[i][j] = 1;
				flag = true;
			}

			//BFS();
			Calc();

			//다시 원상태로.
			if (flag) {
				arr[i][j] = 0;
			}
		}
	}

	cout << ans;
}