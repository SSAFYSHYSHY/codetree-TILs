#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int n, m, max_ans = 0, ans = 0, cnt = 1;
int arr[501][501];
int new_arr[501][501];
int score[501][501];

bool visited[501][501] = { false, };
queue<pair<int, int>> q;

void Initial() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			new_arr[i][j] = arr[i][j];
			visited[i][j] = false;
			score[i][j] = 0;
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

			if (InRange(nx, ny) && new_arr[nx][ny] == 1 && !visited[nx][ny]) {
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
				score[nx][ny] = cnt;
				cnt++;
			}
		}
	}
}

int Calc(int x, int y, int flag) {
	//초기화.
	Initial();

	//해당 배열을 바꿈.
	if (flag == 0) {
		new_arr[x][y] = 1;
	}
	else {
		new_arr[x][y] = 0;
	}

	//BFS() 작업.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (new_arr[i][j] == 1 && !visited[i][j]) {
				cnt = 1;
				q.push(make_pair(i, j));
				visited[i][j] = true;
				score[i][j] = cnt++;
				BFS();
			}
		}
	}

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < m; j++) {
	//		cout << score[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << "\n";

	//최대값 찾아서 반환.
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (maxi < score[i][j]) {
				maxi = score[i][j];
			}
		}
	}

	return maxi;
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
			if (arr[i][j] == 0) {
				ans = Calc(i, j, 0);
				max_ans = max(max_ans, ans);
			}
			else {
				ans = Calc(i, j, 1);
				max_ans = max(max_ans, ans);
			}
		}
	}

	cout << max_ans;
}