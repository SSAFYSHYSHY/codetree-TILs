#include <iostream>

using namespace std;

int n, m, q;
int arr[101][101];
int temp[101][101];

//회전.
void Calc(int sx, int sy, int  ex, int ey) {
	int tmp = arr[sx][sy];

	//위로 이동.
	for (int i = sx; i < ex; i++) {
		arr[i][sy] = arr[i + 1][sy];
	}

	//왼쪽으로 이동.
	for (int i = sy; i < ey; i++) {
		arr[ex][i] = arr[ex][i + 1];
	}


	//아래로 이동.
	for (int i = ex; i > sx; i--) {
		arr[i][ey] = arr[i - 1][ey];
	}

	//오른쪽으로 이동.
	for (int i = ey; i > sy; i--) {
		arr[sx][i] = arr[sx][i-1];
	}

	arr[sx][sy + 1] = tmp;
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int Calc3(int x, int y) {
	int dx[] = { 0, -1,0,1,0 };
	int dy[] = { 0, 0,-1,0,1 };

	int sum = 0;
	int len = 0;

	for (int k = 0; k < 5; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (InRange(nx, ny)) {
			sum += arr[nx][ny];
			len++;
		}
	}

	return sum / len;
}

//평균 값.
void Calc2(int sx, int sy, int ex, int ey) {
	for (int i = sx; i <= ex; i++) {
		for (int j = sy; j <= ey; j++) {
			temp[i][j] = Calc3(i, j);
		}
	}

	for (int i = sx; i <= ex; i++) {
		for (int j = sy; j <= ey; j++) {
			arr[i][j] = temp[i][j];
		}
	}

}

int main() {
	cin >> n >> m >> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	while (q--) {
		int sx, sy, ex, ey;

		cin >> sx >> sy >> ex >> ey;

		Calc(sx - 1, sy - 1, ex - 1, ey - 1);

		Calc2(sx - 1, sy- 1, ex - 1, ey - 1);

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

}