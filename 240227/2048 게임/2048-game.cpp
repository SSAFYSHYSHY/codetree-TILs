#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

int board[21][21];
int arr[21][21];
int new_arr[21][21];
int new_arr2[21][21];
vector<int> v;

int n, ans = 0;

void Initial() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			new_arr[i][j] = 0;
			new_arr2[i][j] = 0;
			arr[i][j] = 0;
			arr[i][j] = board[i][j];
		}
	}
}

void Initial2() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			new_arr[i][j] = 0;
			new_arr2[i][j] = 0;
		}
	}
}

void Copy() {
	//배열 복사.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = new_arr2[i][j];
		}
	}
}

void Rotate(int idx) {
	// 0,1,2,3
	// 위,아래,왼쪽,오른쪽.

	if (idx == 0) {
		for (int j = 0; j < n; j++) {
			int temp = 0;
			for (int i = 0; i < n; i++) {
				if (arr[i][j] > 0) {
					new_arr[temp][j] = arr[i][j];
					temp++;
				}
				else {
					continue;
				}
			}
		}

		for (int j = 0; j < n; j++) {
			for (int i = 0; i < n; i++) {

				if (new_arr[i][j] == new_arr[i + 1][j]) {
					new_arr[i][j] += new_arr[i][j];
					new_arr[i + 1][j] = 0;
				}
			}
		}

		for (int j = 0; j < n; j++) {
			int temp = 0;
			for (int i = 0; i < n; i++) {
				if (new_arr[i][j] > 0) {
					new_arr2[temp][j] = new_arr[i][j];
					temp++;
				}
				else {
					continue;
				}
			}
		}
	}
	else if (idx == 1) 
		for (int j = 0; j < n; j++) {
			int temp = n - 1;
			for (int i = n - 1; i >= 0; i--) {
				if (arr[i][j] > 0) {
					new_arr[temp][j] = arr[i][j];
					temp--;
				}
				else{
					continue;
			}
		}

		for (int j = 0; j < n; j++) {
			for (int i = n - 1; i > 0; i--) {
				if (new_arr[i][j] == new_arr[i - 1][j]) {
					new_arr[i][j] += new_arr[i][j];
					new_arr[i - 1][j] = 0;
				}
			}
		}

		for (int j = 0; j < n; j++) {
			int temp = n - 1;
			for (int i = n - 1; i >= 0; i--) {
				if (new_arr[i][j] > 0) {
					new_arr2[temp][j] = new_arr[i][j];
					temp--;
				}
				else {
					continue;
				}
			}
		}
	}
	else if (idx == 2) {
		for (int i = 0; i < n; i++) {
			int temp = 0;
			for (int j = 0; j < n; j++) {
				if (arr[i][j] > 0) {
					new_arr[i][temp] = arr[i][j];
					temp++;
				}
				else {
					continue;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (new_arr[i][j] == new_arr[i][j + 1]) {
					new_arr[i][j] += new_arr[i][j];
					new_arr[i][j + 1] = 0;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			int temp = 0;
			for (int j = 0; j < n; j++) {
				if (new_arr[i][j] > 0) {
					new_arr2[i][temp] = new_arr[i][j];
					temp++;
				}
				else {
					continue;
				}
			}
		}
	}
	else if (idx == 3) {
		for (int i = 0; i < n; i++) {
			int temp = n - 1;
			for (int j = n - 1; j >= 0; j--) {
				if (arr[i][j] > 0) {
					new_arr[i][temp] = arr[i][j];
					temp--;
				}
				else {
					continue;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = n - 1; j > 0; j--) {
				if (new_arr[i][j] == new_arr[i][j - 1]) {
					new_arr[i][j] += new_arr[i][j];
					new_arr[i][j] = 0;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			int temp = n - 1;
			for (int j = n - 1; j >= 0; j--) {
				if (new_arr[i][j] > 0) {
					new_arr2[i][temp] = new_arr[i][j];
					temp--;
				}
				else {
					continue;
				}
			}
		}
	}
}

int Calc() {
	//초기화.
	Initial();

	//방향에 따른 시뮬.
	for (int i = 0; i < v.size(); i++) {

		Initial2();

		int idx = v[i];

		//회전.
		Rotate(idx);

		Copy();
	}


	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] > ans) {
				ans = arr[i][j];
			}
		}
	}

	return ans;
}

void Back(int now) {
	if (now == 5) {
		ans = max(ans, Calc());

		//for (int i = 0; i < v.size(); i++) {
		//	cout << v[i] << " ";
 	//	}
		//cout << "\n";
		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < n; j++) {
		//		cout << arr[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n";

		return;
	}

	for (int i = 0; i < 4; i++) {
		v.push_back(i);
		Back(now + 1);
		v.pop_back();
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}

	//idx, cnt
	Back(0);

	cout << ans;
}