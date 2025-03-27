#include <iostream>
#include <queue>

using namespace std;

int r, c, k;
int arr[73][70];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

bool visited[73][70];
int ans;

bool InRange(int y, int x) {
	return 3 <= y && y < r + 3 && 0 <= x && x < c;
}

void Reset() {
	for (int i = 0; i < r + 3; i++) {
		for (int j = 0; j < c; j++) {
			arr[i][j] = 0;
			visited[i][j] = false;
		}
	}
}

int BFS(int y, int x) {
	int result = y;
	queue<pair<int, int>> q;
	bool visit[73][71];

	for (int i = 0; i < r + 3; i++) {
		for (int j = 0; j < c; j++) {
			visit[i][j] = false;
		}
	}

	q.push({ y,x });
	visit[y][x] = true;

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = cur.first + dy[k];
			int nx = cur.second + dx[k];

			if (InRange(ny, nx) && !visit[ny][nx] && (arr[ny][nx] == arr[cur.first][cur.second] || (arr[ny][nx] != 0 && visited[cur.first][cur.second]))) {
				q.push({ ny,nx });
				visit[ny][nx] = true;
				result = max(result, ny);
			}
		}
	}
	return result;
}

bool Go(int y, int x) {
	bool flag = 0 <= x - 1 && x + 1 < c && y + 1 < r + 3;

	flag = flag && (arr[y - 1][x - 1] == 0);
	flag = flag && (arr[y - 1][x] == 0);
	flag = flag && (arr[y - 1][x + 1] == 0);
	flag = flag && (arr[y][x - 1] == 0);
	flag = flag && (arr[y][x] == 0);
	flag = flag && (arr[y][x + 1] == 0);
	flag = flag && (arr[y + 1][x] == 0);
	return flag;
}

void Down(int y, int x, int d, int id) {
	if (Go(y + 1, x)) {
		Down(y + 1, x, d, id);
	}
	else if (Go(y + 1, x - 1)) {
		Down(y + 1, x - 1, (d + 3) % 4, id);
	}
	else if (Go(y + 1, x + 1)) {
		Down(y + 1, x + 1, (d + 1) % 4, id);
	}
	else {
		if (!InRange(y - 1, x - 1) || !InRange(y + 1, x + 1)) {
			Reset();
		}
		else {
			arr[y][x] = id;

			for (int k = 0; k < 4; k++)
				arr[y + dy[k]][x + dx[k]] = id;

			visited[y + dy[k]][x + dx[k]] = true;
			ans += BFS(y, x) - 3 + 1;
		}
	}


}

int main() {
	cin >> r >> c >> k;

	for (int i = 1; i <= k; i++) {
		int x, d;
		cin >> x >> d;
		x--;
		Down(0, x, d, i);
	}

	cout << ans + 4;

}