#include <iostream>

using namespace std;

int n, m, r, c;
int arr[101][101];
char crr[10001];

int dice[3][3] = {
	{0, 5, 0},
	{4, 6, 3},
	{0 ,2, 0}
};

int dice_dir[4][2] = {
	//L,R,U,D;
	//x y
	{0,-1},
	{0,1},
	{-1,0},
	{1,0}
};

void Calc(char d) {
	if (d == 'R') {
		int temp[3] = { dice[1][1], dice[1][2], 7 - dice[1][1] };
		dice[1][0] = temp[0];
		dice[1][1] = temp[1];
		dice[1][2] = temp[2];
	}
	else if (d == 'L') {
		int temp[3] = { 7 - dice[1][1], dice[1][0], dice[1][1] };
		dice[1][0] = temp[0];
		dice[1][1] = temp[1];
		dice[1][2] = temp[2];
	}
	else if (d == 'D') {
		int temp[3] = { dice[1][1], dice[2][1], 7-dice[1][1]};
		dice[0][1] = temp[0];
		dice[1][1] = temp[1];
		dice[2][1] = temp[2];
	}
	else if (d == 'U') {
		int temp[3] = { 7 - dice[1][1], dice[0][1], dice[1][1]};
		dice[0][1] = temp[0];
		dice[1][1] = temp[1];
		dice[2][1] = temp[2];
	}

	/*for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << dice[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";*/

}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

int main() {
	cin >> n >> m >> r >> c;

	for (int i = 0; i < m; i++){
		cin >> crr[i];
	}

	r -= 1;
	c -= 1;

	arr[r][c] = dice[1][1];

	for (int i = 0; i < m; i++) {
		char dir = crr[i];
		int l = 0;

		if (dir == 'L') {
			l = 0;
		}
		else if (dir == 'R') {
			l = 1;
		}
		else if (dir == 'U') {
			l = 2;
		}
		else if (dir == 'D') {
			l = 3;
		}

		int d_x = dice_dir[l][0];
		int d_y = dice_dir[l][1];

		//cout << l << "\n" ;

		int nx = r + d_x;
		int ny = c + d_y;

		if (!InRange(nx, ny)) {
			continue;
		}

		r = nx;
		c = ny;

		//cout << r << " " << c << "\n";

		Calc(dir);

		/*for (int x = 0; x < n; x++) {
			for (int y = 0; y < n; y++) {
				cout << arr[x][y] << " ";
			}
			cout << "\n";
		}
		cout << "\n";*/

		arr[r][c] = dice[1][1];
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j]) {
				ans += arr[i][j];
			}
		}
	}
	cout << ans << "\n";

}