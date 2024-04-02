#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int r, c, k;
int arr[201][201];
int n =3 , m = 3;

int Calc_row(int row) {
	vector<pair<int, int>> v;
	for (int i = 1; i <= 100; i++) {
		int cnt = 0;

		for (int j = 1; j <= m; j++) {
			if (arr[row][j] == i) {
				cnt++;
			}
		}

		if (cnt) {
			v.push_back(make_pair(cnt, i));
		}
	}

	for (int i = 1; i <= m; i++) {
		arr[row][i] = 0;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		int cnt, num;

		tie(cnt, num) = v[i];

		arr[row][i * 2 + 1] = num;
		arr[row][i * 2 + 2] = cnt;
	}

	return v.size() * 2;
}

int Calc_col(int col) {
	vector<pair<int, int>> v;

	for (int i = 1; i <= 100; i++) {
		int cnt = 0;

		for (int j = 1; j <= n; j++) {
			if (arr[j][col] == i) {
				cnt++;
			}
		}

		if (cnt) {
			v.push_back(make_pair(cnt, i));
		}
	}

	for (int i = 1; i <= n; i++) {
		arr[i][col] = 0;
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		int cnt, num;
		tie(cnt, num) = v[i];

		arr[2 * i + 1][col] = num;
		arr[2 * i + 2][col] = cnt;
	}

	return (int)v.size() * 2;
}

void Calc() {
	if (n >= m) {
		int max_col = 0;
		for (int r = 1; r <= n; r++) {
			max_col = max(max_col, Calc_row(r));
		}
		m = max_col;
	}
	else {
		int max_row = 0;
		for (int c = 1; c <= m; c++) {
			max_row = max(max_row, Calc_col(c));
		}
		n = max_row;
	}
}

int main() {
	cin >> r >> c >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	for(int num = 0 ; num <= 100 ; num++){
		if (arr[r][c] == k) {
			cout << num;
			return 0;
		}

		Calc();
	}

	cout << -1 << "\n";
	return 0;
}