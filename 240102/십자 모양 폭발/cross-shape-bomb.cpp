#include <iostream>

using namespace std;

int n, r,c;
int arr[201][201];
int temp[201][201];

bool InRange(int x, int y, int x1, int y1, int num) {
	return (x == x1 || y == y1) && abs(x - x1) + abs(y - y1) < num;
}
 
void Calc(int x, int y) {
	int num = arr[x][y];

	//폭탄이 터질 위치를 0으로 채워줌.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (InRange(i, j, x, y, num)) {
				arr[i][j] = 0;
			}
		}
	}

	//폭탄이 터지고 저장.
	for (int j = 0; j < n; j++) {
		int ny = n - 1;
		for (int i = n - 1; i >= 0; i--) {
			if (arr[i][j]) {
				temp[ny--][j] = arr[i][j];
			}
		}
	}

	//arr에 복사.
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
			cin >> arr[i][j];
		}
	}
	cin >> r >> c;

	Calc(r - 1, c - 1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

}