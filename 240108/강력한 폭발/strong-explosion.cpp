#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int shape[4][5][2] = {
	{},
	{{-2,0},{-1,0},{0,0}, {1,0},{2,0}},
	{{-1,0},{1,0},{0,0}, {0,-1},{0,1}},
	{{-1,-1},{-1,1},{0,0}, {1,-1},{1,1}},
};

int n, cnt, ans = 0;
int arr[21][21];
int new_arr[21][21];
int goal[21][21];
vector<int> v;

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void Calc3(int x, int y, int num) {
	for (int i = 0; i < 5; i++) {
		int nx = x + shape[num][i][0];
		int ny = y + shape[num][i][1];

		if (InRange(nx, ny)) {
			new_arr[nx][ny] = 1;
		}
	}
}

int Calc2() {
	//초기호 작업.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			new_arr[i][j] = 0;
		}
	}

	//좌표에 v[] 값 줌.
	int num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (goal[i][j]) {
				goal[i][j] = v[num];
				num++;

				//좌표 연산.
				Calc3(i, j, goal[i][j]);
			}
		}
	}

	//복사 작업.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = new_arr[i][j];
		}
	}

	//색칠된 곳 합 연산.
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j]) {
				ans++;
			}
		}
	}

	return ans;
}

void Calc(int num) {
	if (num == cnt) {
		ans = max(ans, Calc2());
		return;
	}

	for (int i = 1; i <= 3; i++) {
		v.push_back(i);
		Calc(num + 1);
		v.pop_back();
	}
}

int main() {
	cin >> n;

	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];

			if (arr[i][j]) {
				cnt++;
				goal[i][j] = 1;
			}
		}
	}

	Calc(0);

	cout << ans;
}