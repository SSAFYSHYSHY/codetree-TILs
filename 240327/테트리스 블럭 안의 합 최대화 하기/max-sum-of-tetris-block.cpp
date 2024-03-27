#include <iostream>
#include <algorithm>

using namespace std;

int arr[201][201];
int n, m, ans = 0;
int new_arr[201][201];

int tetris[5][3][4] = {
	{{1,1,1,1},
	{0,0,0,0},
	{0,0,0,0}},

	{{1,1,0,0},
	{1,1,0,0},
	{0,0,0,0}},

	{{1,0,0,0},
	{1,0,0,0},
	{1,1,0,0}},

	{{1,0,0,0},
	{1,1,0,0},
	{0,1,0,0}},

	{{1,0,0,0},
	{1,1,0,0},
	{1,0,0,0}},
};

//void Print() {
//	cout << "\n";
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			cout << new_arr[i][j] << " ";
//		}
//		cout << "\n";
//	}
//	cout << "\n";
//}

int Sum(int i, int j, int num) {
	int sum = 0;

	for (int x = i; x < i + 3; x++) {
		for (int y = j; y < j + 4; y++) {
			if (tetris[num][x - i][y - j] == 1) {
				sum += arr[x][y];
			}
		}
	}

	return sum;
}

void Calc() {
	for (int i = 0; i < 5; i++) {

		for (int x = 0; x < n; x++) {
			for (int y = 0; y < m; y++) {
				ans = max(ans, Sum(x, y, i));
			}
		}
	}
}

void Rotate(int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			new_arr[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			new_arr[j][m - i - 1] = arr[i][j];
		}
	}

	//Print();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = new_arr[i][j];
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		//각 함수별로 최대값을 반환.
		Calc();
		//cout << ans << " ";

		int temp = n;
		n = m;
		m = temp;

		//회전.
		Rotate(n ,m);

		//Print();
	}

	cout << ans;

}