#include <iostream>

using namespace std;

int n, m, k, cnt = 0;
int arr[101][101];
int dir_arr[101][101];

//L,R,U,D;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

pair<int, int> head = { 0,0 };
pair<int, int> tail = { 0,0 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

bool Calc(int dir, int walk) {
	for (int i = 0; i < walk; i++) {
		dir_arr[head.first][head.second] = dir;
		int nx = head.first + dx[dir];
		int ny = head.second + dy[dir];

		//범위 밖을 벗어난 경우.		
		if (!InRange(nx, ny)) {
			return true;
		}
		//뱀의 범위에 부딪힘 그런데 꼬리가 아님.
		if (arr[nx][ny] == 1 && (nx != tail.first || ny != tail.second)) {
			return true;
		}

		//다음 위치가 사과.
		if (arr[nx][ny] == 2) {
			head.first = nx;
			head.second = ny;
			arr[head.first][head.second] = 1;
			continue;
		}

		//사과가 아님.
		head.first = nx;
		head.second = ny;
		arr[head.first][head.second] = 1;

		//꼬리의 움직임.
		int dirt = arr[tail.first][tail.second];
		arr[tail.first][tail.second] = 0;
		tail.first += dx[dirt];
		tail.second += dy[dirt];

		cnt++;
	}

	return false;
}

int main() {
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		arr[x - 1][y - 1] = 2;
	}
	arr[0][0] = 1;

	int dir[255];
	dir['L'] = 0;
	dir['R'] = 1;
	dir['U'] = 2;
	dir['D'] = 3;

	bool flag = false;
	while (!flag && k--) {
		char c;
		int d;

		flag = true;
		cin >> c >> d;

		flag = Calc(dir[c], d);
	}

	cout << cnt;
}