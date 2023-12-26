#include <iostream>

using namespace std;

int n, m;
int arr[101][101];

//행 연산.
bool Calc(int num, int flag) {
	if (flag == 0) {
		int cnt = 1;
		for (int i = 0; i < n - 1; i++) {
			if (arr[i][num] == arr[i + 1][num]) {
				cnt++;
			}
		}

		if (cnt >= m) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		int cnt = 1;
		for (int i = 0; i < n - 1; i++) {
			if (arr[num][i] == arr[num][i+1]) {
				cnt++;
			}

		}

		if (cnt >= m) {
			return true;
		}
		else {
			return false;
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

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (Calc(i , 0)) {
			cnt++;
		}
		if (Calc(i, 1)) {
			cnt++;
		}
	}

	cout << cnt;
}