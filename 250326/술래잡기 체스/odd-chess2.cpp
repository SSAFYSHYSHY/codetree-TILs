#include <iostream>
#include <algorithm>

using namespace std;

int dx[] = { -1,-1,0,1,1,1,0,-1 };
int dy[] = { 0,-1,-1,-1,0,1,1,1 };
int s_x = 0, s_y = 0, dir = 0, ans = 0, score = 0;
int p, d;

pair<int, int> arr[11][11];

void Input() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int num, dir;
			cin >> num >> dir;

			arr[i][j] = { num,dir - 1 };
		}
	}
	
	//초기 점수, 방향에 대한 길.
	score = arr[s_x][s_y].first;
	dir = arr[s_x][s_y].second;
	arr[s_x][s_y] = { -2,-2 };
}

bool InRange(int x, int y) {
	return 0 <= x && x < 4 && 0 <= y && y < 4;
}

bool OutRange(int x, int y, int dir) {
	for (int i = 1; i <= 4; i++) {
		int nx = x + dx[dir] * i;
		int ny = y + dy[dir] * i;

		if (InRange(nx, ny) && arr[x][y] != make_pair(-1,-1)) {
			return false;
		}
	}

	return true;
}

tuple<int, int, int> Get(int x, int y, int move_dir) {
	for (int i = 0; i < 8; i++) {
		int adj = (move_dir + i) % 8;

		int nx = x + dx[adj];
		int ny = y + dy[adj];

		if (InRange(nx, ny) && arr[x][y] != make_pair(-2, -2)) {
			return make_tuple(nx, ny, adj);
		}
	}

	return make_tuple(x, y, move_dir);
}

void Swap(int x, int y, int nx, int ny) {
	pair<int, int> temp_p = arr[x][y];

	arr[x][y] = arr[nx][ny];
	arr[nx][ny] = temp_p;
}

//이동.
void Move(int tar_num) {
	for (int x = 0; x < 4; x++) {
		for (int y = 0; y < 4; y++) {
			int p_num, p_dir;
			tie(p_num, p_dir) = arr[x][y];

			if (p_num == tar_num) {
				int nx, ny, ndir;
				tie(nx, ny, ndir) = Get(x, y, p_dir);

				arr[x][y] = make_pair(p_num, ndir);
				Swap(x, y, nx, ny);

				return;
			}
		}
	}
}

void MoveAll() {
	for (int i = 1; i <= 16; i++) {
		Move(i);
	}
}

void Back(int cx, int cy, int cdir, int score) {
	//갈 수 없으면 반환.
	if (OutRange(cx, cy, cdir)) {
		ans = max(ans, score);
		return;
	}

	//갈 수 있는 곳에 대해서 찾으면 가자.
	int ndir = 0;
	for (int i = 1; i <= 4; i++) {
		int nx = cx + dx[cdir] * i;
		int ny = cy + dy[cdir] * i;

		if (!(InRange(nx, ny) && (arr[nx][ny] != make_pair(-1,-1)))) continue;

		pair<int, int> copy_arr[4][4];
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				copy_arr[j][k] = arr[j][k];
			}
		}

		//말을 잡고.
		int next_score, next_dir;
		tie(next_score, next_dir) = arr[nx][ny];
		arr[nx][ny] = { -2,-2 };
		arr[cx][cy] = { -1,-1 };

		//도둑 말 이동..
		MoveAll();

		//백트래킹 진행.
		Back(nx, ny, next_dir, score + next_score);

		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				arr[j][k] = copy_arr[j][k];
			}
		}
	}
}

int main() {
	Input();

	//이동.
	MoveAll();

	//백트래킹으로 가장 높은 점수를 가져감.
	Back(s_x, s_y, dir, score);

	cout << ans;
}