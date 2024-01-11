#include <iostream>

using namespace std;

int arr[101][101];
int new_arr[101][101];
bool visited[101][101];
int n, m;

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

bool CanGo(int x, int y) {
	if (!InRange(x, y)) {
		return false;
	}
	if (visited[x][y] || arr[x][y] == 0) {
		return false;
	}
	return true;
}

void DFS(int x, int y) {
	int dx[] = {1,0};
	int dy[] = {0,1};

	for (int i = 0; i < 2; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (CanGo(nx,ny)) {
			new_arr[nx][ny] = 1;
			visited[nx][ny] = true;
			DFS(nx, ny);
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

	new_arr[0][0] = 1;
	visited[0][0] = true;
	DFS(0, 0);

	cout << new_arr[n - 1][m - 1];

}