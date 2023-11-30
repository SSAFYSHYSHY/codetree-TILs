#include <iostream>

using namespace std;

int n, m, q;
int arr[101][101];

void Move(int i, int dir) {

	//오른쪽으로 dir = 1;
	if (dir == 1) {
		int temp = arr[i][0];

		for (int j = 0; j < m - 1; j++) {
			arr[i][j] = arr[i][j + 1];
		}

		arr[i][m-1] = temp;

	}

	//왼쪽으로
	else {
		int temp = arr[i][m-1];

		for (int j = m-1; j >= 1; j--) {
			arr[i][j] = arr[i][j - 1];
		}

		arr[i][0] = temp;
	}
}

bool InRange(int x, int x2) {
	for (int i = 0; i < m; i++) {
		if (arr[x][i] == arr[x2][i]) {
			return false;
		}
	}

	return true;
}

void Calc(int a, char c) {
	int dir = 0, x , y;

	if (c == 'L') {
		dir = 0;
	}
	else if (c == 'R') {
		dir = 1;
	}
	x = dir;
	y = dir;

	if (dir == 0) { //왼
		int temp = arr[a - 1][m - 1];

		for (int i = m - 1; i >= 1; i--) {
			arr[a - 1][i] = arr[a - 1][i - 1];
		}

		arr[a - 1][0] = temp;
	}
	else {
		int temp = arr[a - 1][0];

		for (int i = 0; i < m-1; i++) {
			arr[a - 1][i] = arr[a - 1][i + 1];
		}

		arr[a - 1][m-1] = temp;
	}

	//위쪽시작.
	for (int i = a - 2; i >= 0; i--) {	
		if (!InRange(i + 1, i)) {


			dir = (x + 1) % 2;

			Move(i , dir);
			x++;
		}
	}

	//아래쪽시작.
	for (int i = a ; i < n; i++) {

		if (!InRange(i - 1, i)) {
			dir = (y + 1) % 2;

			Move(i , dir);
			y++;
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

	for (int i = 0; i < q; i++) {
		int a;
		char c;

		cin >> a >> c;

		Calc(a, c);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}