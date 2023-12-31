#include <iostream>

using namespace std;

int n,m,k;
int arr[101][101];

bool Calc2(int x, int y_s, int y_e) {
	for (int i = y_s; i <= y_e; i++) {
		if (arr[x][i] != 0) {
			return false;
		}
	}

	return true;
}

int Calc() {
	for (int i = 0; i < n - 1; i++) {
		if (!Calc2(i + 1, k, k + m - 1)) {
			return i;
		}
	}

	return n - 1;
}

int main() {
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	k -= 1;

	int nx = Calc();

	for (int i = k; i < k + m; i++) {
		arr[nx][i] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}