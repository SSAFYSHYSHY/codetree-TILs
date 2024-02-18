#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, l, r;
queue<pair<int,int>> q;
int arr[51][51];
int new_arr[51][51];
bool visited[51][51] = { false, };
vector<int> v[51][51];

void Total_Initial() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			new_arr[i][j] = 0;
			v[i][j].clear();

			visited[i][j] = false;
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void Calc() {
	int sum = 0;
	int len = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j].size()) {
				sum += v[i][j].front();
				len++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j].size()) {
				new_arr[i][j] = sum / len;
			}
		}
	}


}

bool Same() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != new_arr[i][j]) {
				return false;
			}
		}
	}

	return true;
}

void Copy() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = new_arr[i][j];
		}
	}
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

			if (InRange(nx, ny) && !visited[nx][ny]) {
				if (l <= abs(arr[x][y] - arr[nx][ny]) && abs(arr[x][y] - arr[nx][ny]) <= r) {
					visited[nx][ny] = true;
					v[nx][ny].push_back(arr[nx][ny]);
					q.push(make_pair(nx, ny));
				}
				else {
					continue;
				}
			}
		}
	}

	Calc();
}

int main() {
	cin >> n >> l >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	int ans = 0;

	while (1) {

		Total_Initial();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					v[i][j].push_back(arr[i][j]);
					q.push(make_pair(i, j));
					visited[i][j] = true;
					BFS();
				}
				v[i][j].clear();
			}
		}

		if (Same()) {
			cout << ans;
			return 0;
		}
		else {
			Copy();
			ans++;
		}
	}

	cout << ans;
}