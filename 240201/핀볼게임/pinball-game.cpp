#include <iostream>
#include <algorithm>

using namespace std;

int arr[101][101];
int new_arr[101][101];
int n, ans = 0;
int visited[101][101] = { 0, };

//하,좌,우,상.
int dx[] = { 1, 0,0,-1 };
int dy[] = { 0,-1,1,0 };

enum {
	D,
	L,
	R,
	U
};

void Rotate() {
	//시계 반회전.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			new_arr[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			new_arr[i][j] = arr[j][n - i - 1];

			if (new_arr[i][j] == 1) {
				new_arr[i][j] = 2;
			}
			else if (new_arr[i][j] == 2) {
				new_arr[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = new_arr[i][j];
		}
	}
}

void Initial() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = 0;
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

//방향 연산.
int Calc2(int x, int y, int dir) {
	if (arr[x][y] == 1) {
		if (dir == D) {
			dir = L;
		}
		else if (dir == U) {
			dir = R;
		}
		else if (dir == L) {
			dir = D;
		}
		else if (dir == R) {
			dir = U;
		}
	}
	else if (arr[x][y] == 2) {
		if (dir == D) {
			dir = R;
		}
		else if (dir == U) {
			dir = L;
		}
		else if (dir == L) {
			dir = U;
		}
		else if (dir == R) {
			dir = D;
		}
	}

	return dir;
}

int Calc(int x, int y, int dir) {

	//방문 섹터 초기화.
	Initial();

	//횟수, 해당 좌표의 방문 표시.
	int cnt = 1;

	//범위 밖으로 나가거나 방문이 되었을 때까지 반복.
	while (1) {
		int nx = 0, ny = 0;

		dir = Calc2(x,y,dir);
		nx = x + dx[dir];
		ny = y + dy[dir];

		//가고자 하는 방향 체크.
		//범위 안에 있지 않으면.
		if (!InRange(nx, ny)) {
			return cnt += 1;
		}
		//무한 반복인가. 
		if (visited[nx][ny] == 2) {
			return 0;
		}

		visited[nx][ny]++;
		x = nx;
		y = ny;
		cnt++;
	}

	return cnt;
}

void Simul() {
	for (int i = 0; i < n; i++) {
		int dir = D;

		// 조건을 만족하면 브레이크를 주고
		// cnt 값과의 최대값을 연산한다.
		ans = max(ans, Calc(0, i, dir));
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	//1 -> /   2 -> 
	for (int idx = 0; idx < 4; idx++) {
		//시뮬 시작. 한 줄만 비교하면 됨.
		Simul();

		//시계 반회전.
		Rotate();
	}

	cout << ans;
}