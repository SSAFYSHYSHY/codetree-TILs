#include <iostream>

using namespace std;

int n, m, maxi = 0;
int arr[21][21];
int new_arr[21][21];

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

bool Calc2(int x, int y) {
	if (arr[x][y] > maxi) {
		maxi = arr[x][y];

		return true;
	}
	else {
		return false;
	}
}

void Calc(int x, int y) {
	//new_Arr 초기화.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			new_arr[i][j] = arr[i][j];
		}
	}

	//비교 연산.
	int dx[] = { -1,-1,-1,0,0,1,1,1 };
	int dy[] = { -1,0,1,-1,1,-1,0,1 };
	maxi = 0;
	int x1 = 0, y1 = 0;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (InRange(nx, ny)) {
			if (Calc2(nx, ny)) {
				x1 = nx;
				y1 = ny;
			}
		}
	}

	new_arr[x][y] = arr[x1][y1];
	new_arr[x1][y1] = arr[x][y];

	//new_arr 복사.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = new_arr[i][j];
		}
	}
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int t = 0; t < m; t++) {
		for (int i = 1; i <= n*n; i++) {
			bool flag = false;

			for (int x = 0; x < n; x++) {
				for (int y = 0; y < n; y++) {
					if (arr[x][y] == i && flag == false) {
						Calc(x, y);
						flag = true;
					}
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

}