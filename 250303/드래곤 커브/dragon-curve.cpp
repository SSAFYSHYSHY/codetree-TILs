#include <iostream>
#include <algorithm>

using namespace std;

int n;
int x, y, d, g;

bool curve[101][101];
bool new_arr[101][101];
bool arr[101][101];

pair<int, int> Rotate(int x, int y, int cx, int cy) {
	return make_pair(y - cy + cx, cx - x + cy);
}

void Simul(int x, int y) {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			new_arr[i][j] = false;
		}
	}

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (curve[i][j]) {
				int nx, ny;
				tie(nx, ny) = Rotate(i, j, x, y);

				new_arr[nx][ny] = true;
			}
		}
	}

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (new_arr[i][j]) {
				curve[i][j] = true;
			}
		}
	}
}

void Calc(int x, int y, int d, int g) {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			curve[i][j] = false;
		}
	}

	int dx[] = { 0,-1,0,1 };
	int dy[] = { 1,0,-1,0 };

	int sx = x, sy = y;
	int ex = x + dx[d], ey = y + dy[d];

	curve[sx][sy] = true;
	curve[ex][ey] = true;

	while (g--) {
		Simul(ex, ey);

		tie(ex, ey) = Rotate(sx, sy, ex, ey);
	}

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (curve[i][j]) {
				arr[i][j] = true;
			}
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g;

		Calc(x, y, d, g);
	}

	int ans = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (arr[i][j] && arr[i + 1][j] && arr[i][j + 1] && arr[i + 1][j + 1])
				ans++;
		}
	}
	cout << ans;
}