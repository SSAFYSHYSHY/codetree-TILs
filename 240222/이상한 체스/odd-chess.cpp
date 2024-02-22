#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <climits>

using namespace std;

int arr[9][9];
int dir[9][9];
bool visited[9][9] = {false,};
int n, m, ans =INT_MAX;

vector<pair<int, int>> v;

//북 동 남 서
int chess[6][4] = {
	{},
	{1,0,0,0},
	{0,1,0,1},
	{1,1,0,0},
	{1,1,0,1},
	{1,1,1,1}
};

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void Fill(int sx, int sy, int num, int dir) {
	//북 동 남 서 
	int dx[] = { -1,0,1,0 };
	int dy[] = { 0,1,0,-1 };

	for (int i = 0; i < 4; i++) {
		if (!chess[num][i]) {
			continue;
		}

		int x = sx;
		int y = sy;
		int move_dir = (dir + i) % 4;
		while (1) {
			visited[x][y] = true;
			int nx = x + dx[move_dir];
			int ny = y + dy[move_dir];

			if (InRange(nx, ny) && arr[nx][ny] != 6) {
				x = nx;
				y = ny;
			}
			else {
				break;
			}
		}
	}
}

int Calc() {
	// visited 초기화.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}

	//v 사이즈
	for (int i = 0; i < v.size(); i++) {
		int x, y;
		tie(x, y) = v[i];

		Fill(x, y, arr[x][y], dir[x][y]);
	}


	//ans 값 갱신.
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == false && arr[i][j] != 6) {
				ans++;
			}
		}
	}

	return ans;
}

void Back(int now) {
	if (now == v.size()) {
		ans = min(ans, Calc());
		return;
	}

	int px, py;
	tie(px, py) = v[now];

	for (int i = 0; i < 4; i++) {
		dir[px][py] = i;
		Back(now + 1);
	}
}
 
int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];

			if (1 <= arr[i][j] && arr[i][j] <= 5) {
				v.push_back(make_pair(i, j));
			}
		}
	}

	Back(0);
	cout << ans;
}