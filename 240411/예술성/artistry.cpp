#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[31][31];
int new_arr[31][31];

int group_n;
int group[31][31];
int group_cnt[31 * 31 + 1];

bool visited[31][31];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void DFS(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (InRange(nx, ny) && !visited[nx][ny] && arr[x][y] == arr[nx][ny]) {
			visited[nx][ny] = true;
			group[nx][ny] = group_n;
			group_cnt[group_n]++;
			DFS(nx, ny);
		}
	}
}

void Make() {
	group_n = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				group_n++;
				visited[i][j] = true;
				group[i][j] = group_n;
				group_cnt[group_n] = 1;
				DFS(i, j);
			}
		}
	}
}

int GetScore() {
	int score = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = j + dy[k];

				if (InRange(nx, ny) && arr[i][j] != arr[nx][ny]) {
					int g1 = group[i][j];
					int g2 = group[nx][ny];

					int num1 = arr[i][j];
					int num2 = arr[nx][ny];

					int cnt1 = group_cnt[g1];
					int cnt2 = group_cnt[g2];

					score += (cnt1 + cnt2) * num1 * num2;
				}
			}
		}
	}

	//중복 값 제거.
	return score / 2;
}

int Score() {
	//그룹 만들기.
	Make();

	//모든 점수 구하기.
	return GetScore();
}

void Rotate_S(int sx, int sy, int num) {
	for (int x = sx; x < sx + num; x++) {
		for (int y = sy; y < sy + num; y++) {
			int ox = x - sx;
			int oy = y - sy;

			int rx = oy;
			int ry = num - ox - 1;

			new_arr[rx + sx][ry + sy] = arr[x][y];
		}
	}
}

void Rotate() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			new_arr[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == n / 2) {
				new_arr[j][i] = arr[i][j];
			}
			else if (i == n / 2) {
				new_arr[n - j - 1][i] = arr[i][j];
			}
		}
	}

	int num = n / 2;
	Rotate_S(0, 0, num);
	Rotate_S(0, num + 1, num);
	Rotate_S(num + 1, 0, num);
	Rotate_S(num + 1, num + 1, num);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = new_arr[i][j];
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

	int ans = 0;
	for (int i = 0; i < 4; i++) {
		ans += Score();

		Rotate();
	}

	cout << ans;
}