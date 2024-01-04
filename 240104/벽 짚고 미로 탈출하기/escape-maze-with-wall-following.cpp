#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int n, x, y;
int dx[] = { 0, 1, 0,-1 };
int dy[] = { 1,0,-1,0 };
char arr[101][101];

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

pair<int, int> move(int curr) {
	int cnt = 0;
	int nx = 0, ny = 0;

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

	if (cnt != 4) {
		return make_pair(nx, ny);
	}
	else {
		return make_pair(x, y);
	}
}

bool Calc(int curr) {
	int r = (curr + 1) % 4;

	int nx = x + dx[r];
	int ny = y + dy[r];

	if (arr[nx][ny] == '#') {
		return true;
	}
	else {
		return false;
	}
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

	if (ans != n * n) {
		cout << ans;
	}
	else {
		cout << -1;
	}
}