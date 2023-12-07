#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, k;
int arr[11][11];
int food[11][11];
int new_food[11][11];

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
			new_virus[nx][ny].push_back(1);
		}
	}
}

void Calc() {
	//초기화
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			new_food[i][j] = 0;
			new_virus[i][j].clear();
		}
	}

	//양분 섭취 유무.

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sort(virus[i][j].begin(), virus[i][j].end());

			for (int k = 0; k < (int)virus[i][j].size(); k++) {
				int cnt = virus[i][j][k];

				if (food[i][j] >= cnt) {
					new_virus[i][j].push_back(cnt+1);
					food[i][j] -= cnt;
				}
				else {
					new_food[i][j] += cnt / 2;
				}

			}

			new_food[i][j] += food[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < virus[i][j].size(); k++) {
				if (virus[i][j][k] % 5 == 0) {
					Calc2(i, j);
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			new_food[i][j] += arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			food[i][j] = new_food[i][j];
			virus[i][j] = new_virus[i][j];
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

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			food[i][j] = 5;
		}
	}

	for (int i = 0; i < m; i++) {
		int r, c, n;
		cin >> r >> c >> n;

		virus[r-1][c-1].push_back(n);
	}

	while (k--) {
		Calc();
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans += virus[i][j].size();
		}
	}

	cout << ans;
}