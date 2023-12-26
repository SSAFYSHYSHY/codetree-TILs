#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[201][201];
int box[6][3][3] = {
	{{1,0,0},
	{1,1,0},
	{0,0,0}},
	{{1,1,0},
	{1,0,0},
	{0,0,0}},
	{{1,1,0},
	{0,1,0},
	{0,0,0}},
	{{0,1,0},
	{1,1,0},
	{0,0,0}},
	{{1,1,1},
	{0,0,0},
	{0,0,0}},
	{{1,0,0},
	{1,0,0},
	{1,0,0}},
};

int Calc(int x, int y) {
	int ans = 0;
	
	for (int t = 0; t < 6; t++) {
		bool flag = true;
		int sum = 0;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (box[t][i][j] == 0) continue;
					
				if (x + i >= n || y + j >= m) {
					flag = false;
				}
				else {
					sum += arr[x + i][y + j];
				}
			}
		}

		if (flag) {
			ans = max(ans, sum);
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

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans = max(ans, Calc(i, j));
		}
	}

	cout << ans;
}