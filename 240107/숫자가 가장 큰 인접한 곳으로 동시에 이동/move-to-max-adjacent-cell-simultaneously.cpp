#include <iostream>

using namespace std;

int n, m, t, maxi = 0;
int arr[21][21];
int new_arr[21][21];
int new_arr2[21][21];

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
	int dx[] = {-1,1,0,0};
	int dy[] = {0,0,-1,1};
	int x1 = 0, y1 = 0;
	maxi = 0;


	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		//범위 안에 있을때 
		if (InRange(nx, ny)) {
			//해당 위치와 큰 값 비교. max 값 갱신.
			if (Calc2(nx, ny)) {
				x1 = nx;
				y1 = ny;
			}

		}
	}

	new_arr2[x1][y1]++;
}

int main() {
	cin >> n >> m >> t;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		x -= 1;
		y -= 1;

		new_arr[x][y] = 1;
	}

	while (t--) {
		//new_arr2 초기화.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				new_arr2[i][j] = 0;
			}
		}

		//new_arr에 있으면 연산.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (new_arr[i][j]) {
					Calc(i, j);
				}
			}
		}
		//new_arr2 이상이면 0으로 초기화.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (new_arr2[i][j] >= 2) {
					new_arr2[i][j] = 0;
				}
			}
		}

		//new_arr2에 복사.
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				new_arr[i][j] = new_arr2[i][j];
			}
		}

		// for (int i = 0; i < n; i++) {
		// 	for (int j = 0; j < n; j++) {
		// 		cout << new_arr[i][j] << " ";
		// 	}
		// 	cout << "\n";
		// }
		// cout << "\n";
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << new_arr[i][j] << " ";
		}
		cout << "\n";
	}*/

	//갯수 출력.
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (new_arr[i][j] == 1) {
				cnt++;
			}
		}
	}

	cout << cnt;
}