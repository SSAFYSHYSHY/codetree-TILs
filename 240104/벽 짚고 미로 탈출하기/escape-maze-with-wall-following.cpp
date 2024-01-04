#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int n, x, y;
int dx[] = { 0, 1, 0,-1 };
int dy[] = { 1,0,-1,0 };
vector<vector<char>> arr(101, vector<char>(101));

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

pair<int, int> move(int curr) {
	int cnt = 0;
	int nx, ny;

	for (int i = 0; i < 4; i++) {
		cnt += 1;

		nx = x + dx[curr];
		ny = y + dy[curr];

		if (!InRange(nx, ny)) {
			return make_pair(-1, -1);
		}
		else {
			if (arr[nx][ny] == '#') {
				curr = (curr + 3) % 4;
			}
			else if (arr[nx][ny] == '.') {
				break;
			}
		}
	}

	return make_pair(x, y) == make_pair(nx, ny) ? make_pair(x, y) : make_pair(nx, ny);
}

bool Calc(int curr) {
	int r = (curr + 1) % 4;

	int nx = x + dx[r];
	int ny = y + dy[r];

	return arr[nx][ny] == '#';
}

int main() {
	cin >> n >> x >> y;

	x -= 1;
	y -= 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	int curr = 0;
	int ans = 0;

	for (int i = 0; i < n * n; i++) {
		pair<int, int> pos = move(curr);
		ans += 1;

		if (pos == make_pair(-1, -1)) {
			break;
		}

		tie(x, y) = pos;

		if (!Calc(curr)) {
			curr = (curr + 1) % 4;
		}

	}

	cout << (ans != n * n ? ans : -1) << "\n";
}