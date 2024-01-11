#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, zone_cnt = 0 , ans = 0;
int arr[101][101];
bool visited[101][101];

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y, int k) {
	if (!InRange(x, y)) {
		return false;
	}
	if (visited[x][y] || arr[x][y] != k) {
		return false;
	}

	return true;
}

void Initial() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}
}

void DFS(int x, int y, int k) {
	int dx[] = { -1,1,0,0 };
	int dy[] = {0 , 0,-1,1};

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (CanGo(nx, ny, k)) {
			visited[nx][ny] = true;
			zone_cnt++;
			DFS(nx, ny, k);
		}
	}
}

void Calc(int k) {
	zone_cnt = 1;
	Initial();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (CanGo(i, j, k)) {
				visited[i][j] = true;
				DFS(i, j, k);
			}
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	int ans_cnt = 0;
	for (int k = 1; k <= 100; k++) {
		Calc(k);

		//터지는 개수.
		if (zone_cnt >= 4) {
			ans++;
		}

		//이어져 있는 최대값들.
		if (zone_cnt > ans_cnt) {
			ans_cnt = zone_cnt;
		}


	}

	cout << ans << " " << ans_cnt;
}