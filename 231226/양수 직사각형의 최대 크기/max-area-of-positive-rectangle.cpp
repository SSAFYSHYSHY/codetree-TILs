#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[21][21];
int visited[21][21];

int Rect(int x1, int y1, int x2, int y2) {
	int sum = 0;
	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			if (arr[i][j] < 0) return 0;

			sum += 1;
		}
	}

	return sum;
}

int Calc2(int x1, int y1, int x2, int y2) {
	int sum = 0;
	sum = max(sum, Rect(x1, y1, x2, y2));

	return sum;
}

int Calc() {
	int ans = 0;

	//직사각형.
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
    if(ans == 0) {
        cout << -1;
        return 0;
    }

	cout << ans;
}