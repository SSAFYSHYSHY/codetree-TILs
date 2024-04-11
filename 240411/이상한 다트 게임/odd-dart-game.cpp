#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m, q;
int arr[51][51];
int new_arr[51][51];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void Rotate(int x, int d, int k) {
	while (k--) {
		if (d == 0) {
			for (int i = x; i <= n; i += x) {
				int temp = arr[i][m];
				for (int j = m ; j >= 1; j--) {
					arr[i][j] = arr[i][j - 1];
				}
				arr[i][1] = temp;
			}
		}
		else {
			for (int i = x; i <= n; i += x) {
				int temp = arr[i][1];
				for (int j = 1; j <= m; j++) {
					arr[i][j] = arr[i][j + 1];
				}
				arr[i][m] = temp;
			}
		}
	}
}

bool InRange(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

bool Check() {
	bool ans_flag = false;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			bool flag = false;

			if (arr[i][j] > 0) {

				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (!InRange(nx, ny)) {
						if (1 > ny || ny > m) {
							ny = abs(m - ny);
						}
					}

					if (arr[i][j] == arr[nx][ny]) {
						new_arr[nx][ny] = -2;
						flag = true;
					}
				}
			}

			if (flag == true) {
				new_arr[i][j] = -2;
				ans_flag = true;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (new_arr[i][j] == -2) {
				arr[i][j] = new_arr[i][j];
			}
		}
	}

	if (ans_flag == true) {
		return true;
	}
	else {
		return false;
	}
}

void Norm() {
	int sum = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] > 0) {
				cnt++;
				sum += arr[i][j];
			}
		}
	}
	int avg = 0;
	if (cnt > 0 && sum > 0) {
		avg = sum / cnt;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] > avg && arr[i][j] > 0) {
				arr[i][j] -= 1;
			}
			else if(arr[i][j] < avg && arr[i][j] > 0) {
				arr[i][j] += 1;
			}
		}
	}
}

void Print() {
	cout << "\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int main() {
	cin >> n >> m >> q;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	while (q--) {
		int x, d, k;
		cin >> x >> d >> k;

		//해당 돌림판의 k 만큼 이동.
		Rotate(x, d, k);

		//Print();

		//인접한 부분의 배열이 같으면 -2로 변환.
		bool flag = Check();

		//flag가 true면 정규화 수행.
		if (flag == false) {
			Norm();
		}

		//Print();
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] > 0) {
				ans += arr[i][j];
			}
		}
	}

	cout << ans;

}