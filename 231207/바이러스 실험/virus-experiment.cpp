#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m,k;
int arr[11][11];
int new_arr[11][11];
vector<int> virus[11][11];
vector<int> new_virus[11][11];

bool CanGo(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void Calc2(int x, int y) {
	int dx[] = { -1,-1,-1,0,0,1,1,1 };
	int dy[] = { -1,0,1,-1,1,-1,0,1 };

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (CanGo(nx, ny)) {
			virus[nx][ny].push_back(1);
		}
	}
}

void Calc() {
	//새로운 바이러스와 양분 값을 초기화. 시뮬.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			new_virus[i][j].clear();
			new_arr[i][j] = 0;
		}
	}

	//정렬.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sort(virus[i][j].begin(), virus[i][j].end());
		}
	}

	//양분 판별.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			for (int k = 0; k < virus[i][j].size() ; k++) {
				int age = virus[i][j][k];

				if (arr[i][j] >= age) {
					arr[i][j] -= age;
					new_virus[i][j].push_back(age + 1);
				}
				else {
					new_arr[i][j] += age / 2;
				}
			}

			new_arr[i][j] += arr[i][j];
		}
	}

	//만약 바이러스의 크기가 5의 배수라면.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < virus[i][j].size(); k++) {
				int age = virus[i][j][k];
				if (age % 5 == 0) {
					Calc2(i, j);
				}
			}
		}
	}

	//양분에 + arr 원본씩 추가.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			new_arr[i][j] += arr[i][j];
		}
	}

	//값 갱신.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			virus[i][j] = new_virus[i][j];
			arr[i][j] = new_arr[i][j];
		}
	}
}

int main() {
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int r, c, n;
		cin >> r >> c >> n;

		virus[r][c].push_back(n);
	}

	while (k--) {
		Calc();
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (virus[i][j].size() > 0) {
				ans++;
			}
		}
	}

	cout << ans;
	return 0;
}