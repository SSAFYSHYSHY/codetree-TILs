#include <iostream>

using namespace std;

int n;
int arr[101][101];

int dx[] = { 0,0,1,0,-1 };
int dy[] = { 0,1,0,-1,0 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	int cnt = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i - 1][j] == 0) {
				cnt++;

				for (int k = 0; k < 5; k++) {
					int x = i + dx[k];
					int y = j + dy[k];

					if (InRange(x, y) == false) {
						continue;
					}

					arr[x][y] = 1 - arr[x][y];
				}
			}
		}
	}

	bool flag = true;

	for (int i = 0; i < n; i++) {
		if (arr[n - 1][i] != 1) {
			flag = false;
		}
	}

	if (flag == false) {
		cout << -1;
	}
	else {
		cout << cnt;
	}
}