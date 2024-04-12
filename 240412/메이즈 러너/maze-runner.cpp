#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k;
int arr[11][11];
int new_arr[11][11];

pair<int, int> player[11];
pair<int, int> exits;

int ans;
int sx, sy, s_size;

void Move() {
	for (int i = 1; i <= m; i++) {
		if (player[i].first == exits.first && player[i].second == exits.second) {
			continue;
		}

		if (player[i].first != exits.first) {
			int nx = player[i].first;
			int ny = player[i].second;

			if (exits.first > nx) nx++;
			else nx--;

			if (!arr[nx][ny]) {
				player[i].first = nx;
				player[i].second = ny;
				ans++;
				continue;
			}
		}
		if (player[i].second != exits.second) {
			int nx = player[i].first;
			int ny = player[i].second;

			if (exits.second > ny) ny++;
			else ny--;

			if (!arr[nx][ny]) {
				player[i].first = nx;
				player[i].second = ny;
				ans++;
				continue;
			}
		}

	}
}

void Make() {
	for (int s = 2; s <= n; s++) {
		for (int x = 1; x <= n - s + 1; x++) {
			for (int y = 1; y <= n - s + 1; y++) {
				int x2 = x + s - 1;
				int y2 = y + s - 1;

				//출구가 정사각형 안에 없으면 스킵.
				if (!(x <= exits.first && exits.first <= x2) && (y <= exits.second && exits.second <= y2)) {
					continue;
				}

				bool flag = false;
				for (int l = 1; l <= m; l++) {
					//플레이어가 정사각형 범위 안에 있지만,
					if (x <= player[l].first && player[l].first <= x2 && y <= player[l].second && player[l].second <= y2) {
						//출구에 아닌 경우.
						if (!(player[l].first == exits.first && player[l].second == exits.second)) {
							flag = true;
						}
					}
				}

				if (flag) {
					sx = x;
					sy = y;
					s_size = s;

					return;
				}
			}
		}
	}
}

void Rotate() {
	for (int x = sx; x < sx + s_size; x++) {
		for (int y = sy; y < sy + s_size; y++) {
			if (arr[x][y]) {
				arr[x][y]--;
			}
		}
	}

	for (int x = sx; x < sx + s_size; x++) {
		for (int y = sy; y < sy + s_size; y++) {
			int ox = x - sx;
			int oy = y - sy;

			int rx = oy;
			int ry = s_size - ox - 1;

			new_arr[rx + sx][ry + sy] = arr[x][y];

		}
	}

	for (int x = sx; x < sx + s_size; x++) {
		for (int y = sy; y < sy + s_size; y++) {
			arr[x][y] = new_arr[x][y];
		}
	}
}

void Rotate_2() {
	for (int i = 1; i <= m; i++) {
		int x = player[i].first;
		int y = player[i].second;

		if (sx <= x && x < sx + s_size && sy <= y && y < sy + s_size) {
			int ox = x - sx;
			int oy = y - sy;

			int rx = oy;
			int ry = s_size - ox - 1;

			player[i] = make_pair(rx + sx, ry + sy);
		}
	}

	int x = exits.first;
	int y = exits.second;

	if (sx <= x && x < sx + s_size && sy <= y && y < sy + s_size) {
		int ox = x - sx;
		int oy = y - sy;

		int rx = oy;
		int ry = s_size - ox - 1;

		exits = make_pair(rx + sx, ry + sy);
	}
}

int main() {
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= m; i++) {
		cin >> player[i].first >> player[i].second;
	}

	cin >> exits.first >> exits.second;

	while (k--) {
		//플레이어 이동.
		Move();

		bool flag = true;
		for (int i = 1; i <= m; i++) {
			if (!(player[i].first == exits.first && player[i].second == exits.second)) {
				flag = false;
			}
		}

		if (flag) {
			break;
		}

		//정사각형.
		Make();

		//내부 벽 회전.
		Rotate();

		//모든 참가자들 및 출구 회전.
		Rotate_2();
	}

	cout << ans << "\n";
	cout << exits.first << " " << exits.second << "\n";
}