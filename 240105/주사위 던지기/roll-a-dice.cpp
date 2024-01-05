#include <iostream>

using namespace std;

int arr[101][101];
int n, m, r, c;
int x, y;

int dice[3][3] = {
	{0,5,0},
	{4,6,3},
	{0,2,0}
};

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void Simul(char dir) {
	
    //주사위 시뮬.
	if(InRange(x,y)) {
        if (dir == 'R') {
            for (int i = 0; i < 2; i++) {
                dice[1][i] = dice[1][i + 1];
            }
            dice[1][2] = 7 - dice[1][0];
            y += 1;
        }

        else if (dir == 'L') {
            for (int i = 2; i > 0; i--) {
                dice[1][i] = dice[1][i - 1];
            }
            dice[1][0] = 7 - dice[1][2];
            y -= 1;
        }

        else if (dir == 'D') {
            for (int i = 0; i < 2; i++) {
                dice[i][1] = dice[i+1][1];
            }
            dice[2][1] = 7 - dice[0][1];
            x += 1;
        }

        else if (dir == 'U') {
            for (int i = 2; i > 0; i--) {
                dice[i][1] = dice[i - 1][1];
            }
            dice[0][1] = 7 - dice[2][1];
            x -= 1;
        }

        arr[x][y] = dice[1][1];
    }
}

int main() {
	cin >> n >> m >> r >> c;

	arr[r - 1][c - 1] = 6;
	
	x = r - 1;
	y = c - 1;

	//주사위 굴리기 시뮬.
	for (int i = 0; i < m; i++) {
		char c;
		cin >> c;

		Simul(c);

		// for (int x = 0; x < n; x++) {
		// 	for (int y = 0; y < n; y++) {
		// 		cout << arr[x][y] << " ";
		// 	}
		// 	cout << "\n";
		// }
		// cout << "\n";
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j]) {
				sum += arr[i][j];
			}
		}
	}
	cout << sum;
}