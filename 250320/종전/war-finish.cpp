#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, total_sum = 0, ans = 21e8;
int arr[21][21];
bool border[21][21];

void Input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];

			total_sum += arr[i][j];
		}
	}


}

bool InRange(int x, int y) {
	return  0 <= x && x < n && 0 <= y && y < n;
}

bool Calc(int x, int y, int k, int l) {
	return InRange(x - k, y + k) && InRange(x - k - l, y + k - l) &&
		InRange(x - l, y - l);
}

void Draw(int x, int y, int k, int l) {
	int dx[] = { -1,-1,1,1 };
	int dy[] = { 1,-1,-1,1 };
	int move_num[] = { k,l,k,l };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			border[i][j] = false;
		}
	}

	for (int d = 0; d < 4; d++) {
		for (int q = 0; q < move_num[d]; q++) {
			x += dx[d];
			y += dy[d];
			border[x][y] = true;
		}
	}

}

int Calc2(int x, int y, int k, int l) {
	int pop[6] = {};

	Draw(x, y, k, l);

	for (int i = 0; i < x - l; i++) {
		for (int j = 0; j <= y + k - l && !border[i][j]; j++) {
			pop[0] += arr[i][j];
		}
	}

	for (int i = x - l; i < n; i++) {
		for (int j = 0; j < y && !border[i][j]; j++) {
			pop[1] += arr[i][j];
		}
	}

	for (int i = 0; i <= x - k; i++) {
		for (int j = n - 1; j >= y + k - l + 1 && !border[i][j]; j--) {
			pop[2] += arr[i][j];
		}
	}

	for (int i = x - k + 1; i < n; i++) {
		for (int j = n - 1; j >= y && !border[i][j]; j--) {
			pop[3] += arr[i][j];
		}
	}

	pop[4] = total_sum - pop[0] - pop[1] - pop[2] - pop[3];

	return *max_element(pop, pop + 5) - *min_element(pop, pop + 5);
}

int main() {
	Input();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 1; k < n; k++) {
				for (int l = 1; l < n; l++) {
					if (Calc(i, j, k, l)) {
						ans = min(ans, Calc2(i, j, k, l));
					}
				}
			}
		}
	}

	cout << ans;
}