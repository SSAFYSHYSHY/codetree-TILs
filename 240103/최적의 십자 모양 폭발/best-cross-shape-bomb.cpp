#include <iostream>

using namespace std;

int n;
int arr[51][51];
int arr1[51][51];
int temp[51][51];

void Initial() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = arr1[i][j];
			temp[i][j] = 0;
		}
	}
}

int Calc2(int num) {
	if (num == 0) {
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (arr[i][j] == 0) continue;

				if (arr[i][j] == arr[i][j + 1]) {
					cnt++;
				}
			}
		}
		return cnt;
	}
	else {
		int cnt = 0;

		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n - 1; i++) {
				if (arr[i][j] == 0) continue;

				if (arr[i][j] == arr[i + 1][j]) {
					cnt++;
				}
			}
		}

		return cnt;

	}
}

bool InRange(int x, int y, int x1, int y1, int num) {
	return (x == x1 || y == y1) && (abs(x - x1) + abs(y - y1) < num);
}

void Calc(int x, int y) {
	//폭탄 터지는 위치 연산.
	int num = arr[x][y];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (InRange(i, j, x, y, num)) {
				arr[i][j] = 0;
			}
		}
	}

	//폭탄 연산.
	for (int j = 0; j < n; j++) {
		int cnt = n - 1;
		for (int i = n - 1; i >= 0; i--) {
			if (arr[i][j]) {
				temp[cnt][j] = arr[i][j];
				cnt--;
			}
		}
	}

	//폭탄 저장.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = temp[i][j];
		}
	}

}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr1[i][j];
		}
	}

	int x = 0, y = 0, ans = 0, cnt =0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			Initial();

			Calc(i, j);

			//cout << "\n";
			//for (int i = 0; i < n; i++) {
			//	for (int j = 0; j < n; j++) {
			//		cout << arr[i][j] << " ";
			//	}
			//	cout << "\n";
			//}
			//cout << "\n";

			x = Calc2(0);
			y = Calc2(1);

			//cout << x << " " << y << " " << x + y << "\n";

			cnt = x + y;
			ans = max(ans, cnt);
		}
	}

	cout << ans;
}