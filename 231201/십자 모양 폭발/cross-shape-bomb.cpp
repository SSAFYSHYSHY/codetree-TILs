#include <iostream>

using namespace std;

int arr[201][201];
int temp[201][201];
int n;
int r, c;

bool InRange(int x) {
	return (1 <= x && x <= n);
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	cin >> r >> c;

	int a = arr[r][c];
	a -= 1;


	for (int i = r - a; i <= r + a; i++) {
		if (InRange(i)) {
			arr[i][c] = 0;
		}
	}
	for (int i = c - a; i <= c + a; i++) {
		if (InRange(i)) {
			arr[r][i] = 0;
		}
	}

	for (int i = 1; i <= n; i++) {
		int cnt = n;
		for (int j = n; j >= 1; j--) {
			if (arr[j][i] != 0) {
				temp[cnt][i] = arr[j][i];
				cnt--;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = temp[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

}