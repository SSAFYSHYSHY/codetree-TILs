#include <iostream>

#define BLANK 0
#define CW 0
#define CCW 1

using namespace std;

int n, m, q;
int arr[51][51];
int temp[51];
bool removed[51][51];

void Input() {
	cin >> n >> m >> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
}

void Shift(int row, int d, int k) {
	for (int col = 0; col < m; col++) {
		temp[col] = BLANK;
	}

	if (d == CW) {
		for (int col = 0; col < m; col++) {
			temp[(col + k) % m] = arr[row][col];
		}
	}
	else {
		for (int col = 0; col < m; col++) {
			temp[(col - k + m) % m] = arr[row][col];
		}
	}

	for (int col = 0; col < m; col++) {
		arr[row][col] = temp[col];
	}
}

void Rotate(int x, int d, int k) {
	for (int i = 0; i < n; i++) {
		if ((i + 1) % x == 0) {
			Shift(i, d, k);
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

bool Remove() {
	bool flag = false;
	int dx[] = { 1,-1,0,0 };
	int dy[] = { 0,0,1,-1 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			removed[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == BLANK) continue;

			for (int k = 0; k < 4; k++) {
				int nx = i + dx[k];
				int ny = (j + dy[k] + m) % m;

				if (InRange(nx, ny) && arr[nx][ny] == arr[i][j]) {
					removed[i][j] = removed[nx][ny] = true;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (removed[i][j]) {
				flag = true;
				arr[i][j] = BLANK;
			}
		}
	}

	return flag;
}

void Normal() {
	int total_sum = 0, cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != BLANK) {
				total_sum += arr[i][j];
				cnt++;
			}
		}
	}

	if (cnt > 0) {
		int avg = total_sum / cnt;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == BLANK) {
					continue;
				}

				if (arr[i][j] < avg) {
					arr[i][j]++;
				}
				else if (arr[i][j] > avg) {
					arr[i][j]--;
				}
			}
		}
	}
}

void Calc(int x, int d, int k) {
	Rotate(x, d, k);

	bool flag = Remove();

	if (!flag) {
		Normal();
	}
}

int main() {
	Input();

	while (q--) {
		int x, d, k;
		cin >> x >> d >> k;

		Calc(x, d, k);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != BLANK) {
				ans += arr[i][j];
			}
		}
	}

	cout << ans;
}