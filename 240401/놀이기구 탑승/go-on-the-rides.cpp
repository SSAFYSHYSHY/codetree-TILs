#include <iostream>
#include <algorithm>
#include <cmath>
#include <tuple>

using namespace std;

typedef tuple<int, int, int, int> Cell;

int n;
int arr[401][401];
int tar[401];
bool visited[401][401];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool InRange(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

bool IsFriend(int num1, int num2) {
	return visited[num1][num2];
}

Cell getCell(int num, int x, int y) {
	int cnt = 0, blank_cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (!InRange(nx, ny)) {
			continue;
		}

		if (arr[nx][ny] == 0) {
			blank_cnt++;
		}
		else if (IsFriend(num, arr[nx][ny])) {
			cnt++;
		}
	}

	return make_tuple(cnt, blank_cnt, -x, -y);
}

void Move(int num) {
	Cell best_cell = make_tuple(0, 0, -(n + 1), -(n + 1));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (arr[i][j] == 0) {
				Cell curr = getCell(num, i, j);

				if (best_cell < curr) {
					best_cell = curr;
				}
			}
		}
	}

	int x, y;
	tie(ignore, ignore, x, y) = best_cell;
	arr[-x][-y] = num;
}

int Ans(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (InRange(nx, ny) && IsFriend(arr[x][y], arr[nx][ny])) {
			cnt++;
		}
	}

	return (int)pow(10, cnt - 1);
}

int T_Ans() {
	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += Ans(i, j);
		}
	}

	return ans;
}

int main() {
	cin >> n;

	for (int i = 1; i <= n * n; i++) {
		cin >> tar[i];

		for (int j = 1; j <= 4; j++) {
			int a;
			cin >> a;

			visited[tar[i]][a] = true;
		}
	}

	for (int i = 1; i <= n * n; i++) {
		Move(tar[i]);
	}

	int ans = T_Ans();

	cout << ans;
}