#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

int n, q;
int grid_size;

int arr[65][65];
int new_arr[65][65];

queue<pair<int, int>> v;
bool visited[65][65];

int dx[] = { 0,1,-1,0 };
int dy[] = { 1,0,0,-1 };

void Move(int start_row, int start_col, int half_size, int move_dir) {
	for (int row = start_row; row < start_row + half_size; row++)
		for (int col = start_col; col < start_col + half_size; col++) {
			int next_row = row + dx[move_dir] * half_size;
			int next_col = col + dy[move_dir] * half_size;

			new_arr[next_row][next_col] = arr[row][col];
		}
}

void Rotate(int lev) {
	for (int i = 0; i < grid_size; i++) {
		for (int j = 0; j < grid_size; j++) {
			new_arr[i][j] = 0;
		}
	}

	int box_size = (1 << lev);
	int half_size = box_size / 2;

	for (int i = 0; i < grid_size; i += box_size) {
		for (int j = 0; j < grid_size; j += box_size) {
			Move(i, j, half_size, 0);
			Move(i, j + half_size, half_size, 1);
			Move(i + half_size, j, half_size, 2);
			Move(i + half_size, j + half_size, half_size, 3);
		}
	}

	for (int i = 0; i < grid_size; i++) {
		for (int j = 0; j < grid_size; j++) {
			arr[i][j] = new_arr[i][j];
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < grid_size && 0 <= y && y < grid_size;
}

bool CanGo(int x, int y) {
	return InRange(x, y) && !visited[x][y] && arr[x][y];
}

int Melt_Calc(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (InRange(nx, ny) && arr[nx][ny]) {
			cnt++;
		}
	}

	return cnt;
}

void Calc() {
	for (int i = 0; i < grid_size; i++) {
		for (int j = 0; j < grid_size; j++) {
			new_arr[i][j] = 0;
		}
	}

	for (int i = 0; i < grid_size; i++) {
		for (int j = 0; j < grid_size; j++) {
			int cnt = Melt_Calc(i, j);

			if (arr[i][j] && cnt < 3) {
				new_arr[i][j] = arr[i][j] - 1;
			}
			else {
				new_arr[i][j] = arr[i][j];
			}
		}
	}

	for (int i = 0; i < grid_size; i++) {
		for (int j = 0; j < grid_size; j++) {
			arr[i][j] = new_arr[i][j];
		}
	}

}

int Ices() {
	int cnt = 0;
	for (int i = 0; i < grid_size; i++) {
		for (int j = 0; j < grid_size; j++) {
			cnt += arr[i][j];
		}
	}

	return cnt;
}

int BFS() {
	int size = 0;

	while (!v.empty()) {
		pair<int, int> pp = v.front();
		int cx, cy;
		tie(cx, cy) = pp;
		size++;
		v.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (CanGo(nx, ny)) {
				v.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}

	return size;
}

int Size() {
	int max_size = 0;
	for (int i = 0; i < grid_size; i++) {
		for (int j = 0; j < grid_size; j++) {
			if (arr[i][j] && !visited[i][j]) {
				visited[i][j] = true;
				v.push(make_pair(i, j));
				max_size = max(max_size, BFS());
			}
		}
	}
}

int main() {
	cin >> n >> q;

	grid_size = (1 << n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	while (q--) {
		int lev;
		cin >> lev;

		if (lev) {
			Rotate(lev);
		}

		Calc();
	}

	cout << Ices() << "\n";
	cout << Size();

	return 0;
}