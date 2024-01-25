#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, k, u, d, ans = 0;
int arr[9][9];
bool visited[9][9];
bool check[9][9];
vector<pair<int, int>> v;
queue<pair<int, int>> q;

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void Initial() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			check[i][j] = false;
		}
	}
}

int BFS() {
	Initial();
	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };
	int num, cnt = 0;

	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;
		check[x][y] = true;
		q.push(make_pair(x, y));
	}

	while (!q.empty()) {
		pair<int, int> p = q.front();
		int x = p.first;
		int y = p.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && !check[nx][ny]) {
				num = abs(arr[x][y] - arr[nx][ny]);

				if (u <= num && num <= d) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check[i][j]) {
				cnt++;
			}
		}
	}

	return cnt;
}

void Calc(int x, int y, int num) {
	if (num == k) {
		ans = max(ans, BFS());
		return;
	}

	for (int i = x; i < n; i++) {
		for (int j = y; j < n; j++) {
			if (visited[i][j]) continue;
			
			v.push_back(make_pair(i, j));
			visited[i][j] = true;

			Calc(i, j, num + 1);

			visited[i][j] = false;
			v.pop_back();
		}
	}
}

int main() {
	cin >> n >> k >> u >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	Calc(0, 0, 0);

	cout << ans;
}