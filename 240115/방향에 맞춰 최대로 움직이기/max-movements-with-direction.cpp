#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[4][4];
int dir_arr[4][4];
int ans = 0, cnt = 0;

//1,2,3,4,5,6,7,8
int dx[] = {0,-1,-1,0,1,1,1,0,-1};
int dy[] = {0,0,1,1,1,0,-1,-1,-1};

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y, int num) {
	if (!InRange(x, y)) {
		return false;
	}
	//x, y 는 다음 가고자 하는 곳, num은 이전.
	if (arr[x][y] <= num) {
		return false;
	}

	return true;
}

void Calc(int x, int y, int dir) {
	//n 만큼 반복해야함.
	for (int i = 1; i < n; i++) {
		int nx = x + dx[dir]*i;
		int ny = y + dy[dir]*i;


		if (CanGo(nx, ny, arr[x][y])) {
			//모든 조건이 만족하면.
			cnt++;
			//그 다음 좌표를 방문한다.
			ans = max(ans, cnt);
			Calc(nx, ny, dir_arr[nx][ny]);
			//백트래킹 조건을 줄임.
			cnt--;
		}
	}

}

int main() {
	int x, y, dir;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> dir_arr[i][j];
		}
	}
	cin >> x >> y;

	x -= 1;
	y -= 1;

	Calc(x, y, dir_arr[x][y]);

	cout << ans;

}