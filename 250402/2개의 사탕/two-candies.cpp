#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n, m, ans = 11;
char arr[11][11];
char new_arr[11][11];
vector<int> v;

void Input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = s[j];
		}
	}
}

bool Exist(char tar) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == tar) {
				return true;
			}
		}
	}

	return false;
}

bool Blue() {
	return Exist('B');
}

bool Red() {
	return Exist('R');
}

bool Can(int x, int y) {
	return arr[x][y] == '.' || arr[x][y] == 'O';
}

void Move(int x, int y, int dir) {
	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };

	while (1) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (!Can(nx, ny)) break;

		if (arr[nx][ny] == 'O') {
			arr[x][y] = '.';
			break;
		}

		arr[nx][ny] = arr[x][y];
		arr[x][y] = '.';

		x = nx;
		y = ny;
	}
}

void Calc(int dir) {
	if (dir == 0 || dir == 2) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 'R' || arr[i][j] == 'B') {
					Move(i, j, dir);
				}
			}
		}


	}
	else {
		for (int i = n - 1; i >= 0; i--) {
			for (int j = m - 1; j >= 0; j--) {
				if (arr[i][j] == 'R' || arr[i][j] == 'B') {
					Move(i, j, dir);
				}
			}
		}

	}

}

void Back(int now) {
	//red 탈출구, blue는 위치에 발견시, ans 갱신 return 종료.
	if (!Blue()) return;

	if (!Red()) {
		ans = min(ans, now);
		return;
	}

	//10번이면 종료.
	if (now >= 10) {
		return;
	}

	for (int t = 0; t < 4; t++) {
		//카피.
		char temp[11][11];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				temp[i][j] = arr[i][j];
			}
		}

		//연산 진행.
		Calc(t);

		//이동 가능하면 다음 Back트래킹으로 이동.
		Back(now + 1);

		//다시 원상 복귀.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = temp[i][j];
			}
		}

	}
}

int main() {
	Input();

	Back(0);

	if (ans == 11) {
		ans = -1;
	}
	cout << ans;
}