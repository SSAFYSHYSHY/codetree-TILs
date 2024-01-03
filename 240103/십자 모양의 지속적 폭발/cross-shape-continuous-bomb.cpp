#include <iostream>

using namespace std;

int n, m;
int arr[201][201];
int temp[201][201];

bool InRange(int x, int y, int x1, int y1, int num) {
	return (x == x1 || y == y1) && abs(x - x1) + abs(y - y1) < num;
}

void Calc(int y1) {
	//temp 초기화.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = 0;
		}
	}

	//폭탄 터지는 위치 연산.
	int num = 0;
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i][y1] == 0) {
			continue;
		}
		else {
			num = arr[i][y1];
			x = i;
			y = y1;
			break;
		}
	}

	//폭탄 연산.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (InRange(i, j, x, y, num)) {
				arr[i][j] = 0;
			}
		}
	}

	//폭탄 저장.
	for (int j = 0; j < n; j++) {
		int cnt = n - 1;

		for (int i = n - 1; i >= 0; i--) {
			if (arr[i][j]) {
				temp[cnt--][j] = arr[i][j];
			}
		}
	}


	//arr copy
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = temp[i][j];
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

	for (int i = 0; i < m; i++) {
		int q;
		cin >> q;

		Calc(q - 1);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}