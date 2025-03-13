#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int n, m, h;
int arr[31][11];
int num[11];
vector<pair<int, int>> v;
int ans = 21e8;

bool Calc() {
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
				swap(num[j], num[j+1]);
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

void Back(int curr, int cnt) {
	if (cnt >= ans) {
		return;
	}

	if (Calc()) {
		ans = min(ans, cnt);
	}

	if (cnt == 3 || curr == (int)v.size()) {
		return;
	}

	Back(curr + 1, cnt);

	int a, b;
	tie(a, b) = v[curr];
	arr[a][b] = true;
	Back(curr + 1, cnt + 1);
	arr[a][b] = false;
}

int main() {
	cin >> n >> m >> h;

	for (int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;

		arr[a][b] = true;
	}

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j < n; j++) {
			if (!arr[i][j]) {
				v.push_back({ i,j });
			}
		}
	}

	Back(0, 0);

	if (ans == 21e8) {
		cout << -1;
	}
	cout << ans;
}