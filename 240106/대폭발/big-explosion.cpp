#include <iostream>

using namespace std;

int n, m, r, c;
int arr[101][101];
int new_arr[101][101];

void Initial() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			new_arr[i][j] = 0;
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

int main() {
	cin >> n >> m >> r >> c;

	arr[r - 1][c - 1] = 1;

	for (int t = 1; t <= m; t++) {
		int d = 1 << (t - 1);

		Initial();

		int dx[] = { -1,0,1,0 };
		int dy[] = { 0,-1,0,1 };

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j]) {
					new_arr[i][j] = 1;

					for (int k = 0; k < 4; k++) {
						int nx = i + d * dx[k];
						int ny = j + d * dy[k];

						if (InRange(nx, ny)) {
							new_arr[nx][ny] = 1;
						}
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = new_arr[i][j];
			}
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j]) {
				cnt++;
			}
		}
	}

	cout << cnt;
}