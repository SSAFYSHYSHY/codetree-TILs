#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[6][6];
int visited[6][6];

int Rect(int x1, int y1, int x2, int y2) {
	int sum = 0;
	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			sum += arr[i][j];
		}
	}

	return sum;
}

void Initial() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 0;
		}
	}
}

void Calc3(int x, int y, int x1, int y1) {
	for (int i = x; i <= x1; i++) {
		for (int j = y; j <= y1; j++) {
			visited[i][j]++;
		}
	}
}

bool Visit() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] >= 2) {
				return true;
			}
		}
	}

	return false;
}

bool CanGo(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	Initial();
	Calc3(x1, y1, x2, y2);
	Calc3(x3, y3, x4, y4);
	return Visit();
}

int Calc2(int x1, int y1, int x2, int y2) {
	int sum = -21e8;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = i; k < n; k++) {
				for (int l = j; l < m; l++) {
					if (!CanGo(x1, y1, x2, y2, i, j, k, l)) {
						sum = max(sum, Rect(x1, y1, x2, y2) + Rect(i, j, k, l));
					}
				}
			}
		}
	}

	return sum;
}

int Calc() {
	int ans = -21e8;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = i; k < n; k++) {
				for (int l = j; l < m; l++) {
					ans = max(ans, Calc2(i, j, k, l));
				}
			}
		}
	}

	return ans;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int ans = Calc();

	cout << ans;
}