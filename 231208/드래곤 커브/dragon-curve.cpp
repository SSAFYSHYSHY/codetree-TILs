#include <iostream>
#include <tuple>

using namespace std;

int n;

bool arr[101][101];
bool visited[101][101];
bool new_visited[101][101];

pair<int, int> Rotate(int x, int y, int c_x, int c_y) {
	return make_pair(y - c_y + c_x, c_x - x + c_y);
}

void Calc2(int x, int y) {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			new_visited[i][j] = false;
		}
	}

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (visited[i][j]) {
				int nx, ny;
				tie(nx, ny) = Rotate(i, j, x, y);

				new_visited[nx][ny] = true;
			}
		}
	}

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (new_visited[i][j]) {
				visited[i][j] = true;
			}
		}
	}
}

void Calc(int x, int y, int dir, int g) {
	//초기화
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			visited[i][j] = false;
		}
	}

	//0차 커브 연산
	int dx[] = {0,-1,0,1};
	int dy[] = {1,0,-1,0};

	int s_x = x, s_y = y;
	int e_x = x + dx[dir], e_y = y + dy[dir];

	visited[s_x][s_y] = true;
	visited[e_x][e_y] = true;

	//g 까지 순회.
	while (g--) {
		//커브 확장.
		Calc2(e_x, e_y);

		tie(e_x, e_y) = Rotate(s_x, s_y, e_x, e_y);
	}

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (visited[i][j]) {
				arr[i][j] = true;
			}
		}
	}

}

int main() {
	cin >> n;

	while (n--) {
        int x,y,d,g;
		cin >> x >> y >> d >> g;

		Calc(x, y, d, g);
	}

	int ans = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (arr[i][j] && arr[i + 1][j] && arr[i][j + 1] && arr[i + 1][j + 1]) ans++;
		}
	}

	cout << ans;
}