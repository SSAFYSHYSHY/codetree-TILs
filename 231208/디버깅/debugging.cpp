#include <iostream>
#include <tuple>
#include <vector>
#include <climits>

using namespace std;

int n, m, h;
int arr[31][11];
int num[11];
vector<pair<int, int>> v;
int ans = INT_MAX;

bool Calc2() {
	for (int i = 1; i <= h; i++) {
		for (int j = 2; j < n; j++) {
			if (arr[i][j] && arr[i][j - 1]) {
				return false;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		num[i] = i;
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (arr[i][j]) {
				swap(num[j], num[j + 1]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (num[i] != i) {
			return false;
		}
	}

	return true;
}

void Calc(int idx, int num) {
	if (num >= ans) {
		return;
	}

	if (Calc2()) {
		ans = min(ans, num);
	}

	if (num == 3 || idx == (int)v.size()) {
		return;
	}

	Calc(idx + 1, num);

	int a, b;
	tie(a, b) = v[idx];
	arr[a][b] = true;
	Calc(idx + 1, num + 1);
	arr[a][b] = false;
} 

int main() {
	cin >> n >> m >> h;

	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;
		arr[x][y] = true;
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (!arr[i][j]) {
				v.push_back(make_pair(i, j));
			}
		 }
	}

	Calc(0, 0);

	if (ans == INT_MAX) {
		ans = -1;
	}

	cout << ans;


}