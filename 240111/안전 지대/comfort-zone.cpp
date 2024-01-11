#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, ans = 0, max_ans = 0, zone_cnt = 0;
int arr[51][51] = {0,};
bool visited[51][51] = {false,};

vector<int> v;

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

bool CanGo(int x, int y, int k) {
	if (!InRange(x, y)) {
		return false;
	}
	if (visited[x][y] == true || arr[x][y] <= k) {
		return false;
	}

	return true;
}

void DFS(int x, int y, int num) {
	int dx[] = { -1,1,0,0 };
	int dy[] = {0,0,-1,1};

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (CanGo(nx, ny, num)) {
			visited[nx][ny] = true;
			DFS(nx, ny, num);
		}
	}
}

void Calc(int k) {
	zone_cnt = 0;
	Initial();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (CanGo(i, j, k)) {
				visited[i][j] = true;
				zone_cnt++;
				DFS(i, j, k);
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

	for (int k = 1; k <= 100; k++) {
		Calc(k);

		if (zone_cnt > max_ans) {
			max_ans = zone_cnt;
			ans = k;
		}
	}

	cout << ans << " " << max_ans;
}