#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, L, ans = 0;
int arr[101][101];
int new_arr[101];

int cnt_arr[101];

bool AllSame(int x, int nx){
	for (int i = x; i <= nx; i++) {
		if (new_arr[i] != new_arr[x]) {
			return false;
		}
	}

	return true;
}

bool Calc() {
	//초기화.

	//2 이상 이면 false;
	for (int i = 0; i < n - 1; i++) {
		if (abs(new_arr[i] - new_arr[i + 1]) >= 2) 
			return false;
	}

	for (int i = 0; i < n; i++) {
		cnt_arr[i] = 0;
	}

	//오른쪽 직각삼각형.
	for (int i = 0; i < n - 1; i++) {
		if (new_arr[i] == new_arr[i + 1] + 1) {
			if (i + L >= n) {
				return false;
			}
			if (!AllSame(i+1, i + L)) {
				return false;
			}

			for (int j = i + 1; j <= i + L; j++) {
				cnt_arr[j]++;
			}
		}
	}

	//왼쪽 직각삼각형.
	for (int i = 1; i < n; i++) {
		if (new_arr[i] == new_arr[i - 1] + 1) {
			if (i - L < 0) {
				return false;
			}
			if (!AllSame(i - L, i - 1)) {
				return false;
			}

			for (int j = i - L; j <= i - 1; j++) {
				cnt_arr[j]++;
			}
		}
	}

	//겹쳐 졌다면 false;
	for (int i = 0; i < n; i++) {
		if (cnt_arr[i] >= 2) {
			return false;
		}
	}

	return true;
}

int main() {
	cin >> n >> L;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			new_arr[j] = arr[i][j];
		}

		if (Calc()) {
			ans++;
		}
	}

	for (int j = 0; j < n; j++) {
		for (int i = 0; i < n; i++) {
			new_arr[i] = arr[i][j];
		}

		if (Calc()) {
			ans++;
		}
	}

	cout << ans;
}