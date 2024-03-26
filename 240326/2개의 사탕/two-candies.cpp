#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

char crr[11][11];

int n, m, ans = 11, cnt = 0;

pair<int, int> red;
pair<int, int> blue;
const pair<int, int> OUT = make_pair(n, m);

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool Exit_Red() {
	return red != OUT;
}

bool Exit_Blue() {
	return blue != OUT;
}

 
bool CanGo(int dir) {
	pair<int, int> rp = red;
	pair<int, int> bp = blue;

	if (dir == 0) {
		return (rp.second == bp.second && rp.first < bp.first);
	}
	else if (dir == 1) {
		return (rp.second == bp.second && rp.first > bp.first);
	}
	else if (dir == 2) {
		return (rp.first == bp.first && rp.second < bp.second);
	}
	else {
		return (rp.first == bp.first && rp.second > bp.second);
	}
}

bool InRange(int x, int y) {
	return crr[x][y] != '#' && make_pair(x, y) != red && make_pair(x, y) != blue;
}

pair<int,int> Go(pair<int, int> color, int dir) {
	pair<int, int> p = color;
	int x = p.first;
	int y = p.second;

	int nx = x + dx[dir];
	int ny = y + dy[dir];

	//가로 막힘.
	if (!InRange(nx, ny)) {
		return p;
	}

	//출구라면 맵 밖으로 나감.
	if (crr[nx][ny] == 'O') {
		return OUT;
	}

	return Go(make_pair(nx, ny), dir);

}

void Tilt(int dir) {
	//빨간색 먼저 움직임.
	if (CanGo(dir)) {
		red = Go(red, dir);
		blue = Go(blue, dir);
	}
	else {
		blue = Go(blue, dir);
		red = Go(red, dir);
	}
}

void Back(int num) {
	//B이 출구에 나오면 종료.
	if (!Exit_Blue()) {
		return;
	}

	//R이 탈출구에 나오면, 최소 cnt.
	if (!Exit_Red()) {
		ans = min(ans, num);
		return;
	}

	//cnt가 10 이상이면 반환.
	if (num >= 10) {
		return;
	}

	//각 위치에서 연산. 
	for (int i = 0; i < 4; i++) {
		pair<int, int> t_red = red;
		pair<int, int> t_blue = blue;

		//회전
		Tilt(i);

		//Back()
		Back(num + 1);

		//이전 방향으로 되돌림.
		red = t_red;
		blue = t_blue;
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			crr[i][j] = s[j];

			if (s[j] == 'R') {
				crr[i][j] = '.';
				red = make_pair(i, j);
			}
			else if (s[j] == 'B') {
				crr[i][j] = '.';
				blue = make_pair(i,j);
			}
		}
	}

	//시뮬.
	Back(0);

	if(ans == 11) {
		ans = -1;
	}

	cout << ans;
}