#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

queue<pair<int, int>> q;
int n, m, ans = 0;
int arr[9][9];
int new_arr[9][9];
bool visited[9][9] = {false,};

void Initial() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
			new_arr[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (new_arr[i][j] == 2) {
				q.push(make_pair(i, j));
				visited[i][j] = true;
			}
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

			if (InRange(nx, ny) && !visited[nx][ny] && new_arr[nx][ny] == 0) {
				visited[nx][ny] = true;
				new_arr[nx][ny] = 2; 
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int Calc() {
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

void Print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << new_arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void Back(int now) {
	if (now == 3) {
		Initial();
		BFS();
		//Print();
		ans = max(ans, Calc());
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
				Back(now + 1);
				arr[i][j] = 0;
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
	
	Back(0);

	cout << ans;
}