#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

const pair<int, int> OUT = make_pair(-1, -1);

int arr[21][21];
int dices[7];

bool visited[21][21] = { false, };

int n, m , x, y, k;

int u = 1, f = 2, r = 3;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

pair<int, int> Move(int x, int y, int dir) {
	int nx = x + dx[dir];
	int ny = y + dy[dir];

	if (InRange(nx, ny)) {
		return make_pair(nx, ny);
	}
	else {
		return OUT;
	}
}

void Calc(int dir) {
	//다음 위치.
	pair<int, int> next_pos = Move(x, y, dir);

	if (next_pos == OUT) {
		return;
	}

	tie(x, y) = next_pos;
	
	if (dir == 0) {
		tie(u, f, r) = make_tuple(7 - r, f, u);
	}
	else if (dir == 1) {
		tie(u, f, r) = make_tuple(r, f, 7 - u);
	}
	else if (dir == 2) {
		tie(u, f, r) = make_tuple(f, 7 - u, r);
	}
	else if (dir == 3) {
		tie(u, f, r) = make_tuple(7 - f, u, r);
	} 
	int bottom = 7 - u;

	if (arr[x][y] == 0) {
		arr[x][y] = dices[bottom];
	}
	else {
		dices[bottom] = arr[x][y];
		arr[x][y] = 0;
	}

	cout << dices[u] << "\n";

}

int main() {
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int dir;
		cin >> dir;

		dir -= 1;

		Calc(dir);
	}
}