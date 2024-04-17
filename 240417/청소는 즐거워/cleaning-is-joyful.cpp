#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[501][501];
int x, y, dir , num , ans = 0;

int dice[4][5][5] = {
	{
        {0,  0, 2, 0, 0},
        {0, 10, 7, 1, 0},
        {5,  0, 0, 0, 0},
        {0, 10, 7, 1, 0},
        {0,  0, 2, 0, 0},
    },
    {
        {0,  0, 0,  0, 0},
        {0,  1, 0,  1, 0},
        {2,  7, 0,  7, 2},
        {0, 10, 0, 10, 0},
        {0,  0, 5,  0, 0},
    },
    {
        {0, 0, 2,  0, 0},
        {0, 1, 7, 10, 0},
        {0, 0, 0,  0, 5},
        {0, 1, 7, 10, 0},
        {0, 0, 2,  0, 0},
    },
    {
        {0,  0, 5,  0, 0},
        {0, 10, 0, 10, 0},
        {2,  7, 0,  7, 2},
        {0,  1, 0,  1, 0},
        {0,  0, 0,  0, 0},
    }
};

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void Add(int x, int y, int dust) {
	if (!InRange(x, y)) {
		ans += dust;
	}
	else {
		arr[x][y] += dust;
	}
}

void Move() {
	int dx[] = { 0,1,0,-1 };
	int dy[] = { -1,0,1,0 };

	x += dx[dir];
	y += dy[dir];

	int dust = 0;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			int cnt = arr[x][y] * dice[dir][i][j] / 100;

			Add(x + i - 2, y + j - 2, cnt);

			dust += cnt;
		}
	}

	Add(x + dx[dir], y + dy[dir], arr[x][y] - dust);
}

bool End() {
	return !x && !y;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	x = n / 2;
	y = n / 2;
    num = 1;
    dir = 0;

	while (!End()) {
		for (int i = 0; i < num; i++) {
			Move();

			if (End()) {
				break;
			}
		}

		dir = (dir + 1) % 4;

		if (dir == 0 || dir == 2) {
			num++;
		}
	}

	cout << ans;
}