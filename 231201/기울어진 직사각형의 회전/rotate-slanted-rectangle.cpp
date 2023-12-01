#include <iostream>
#include <vector>

using namespace std;

int arr[101][101];
int temp[101][101];
int n;

using namespace std;

void Calc(int x, int y, int k, int l, int dir) {
	vector<int> dx, dy, nums;

	if (dir == 0) {
		dx = { -1, -1,1,1 };
		dy = { 1,-1,-1,1 };
		nums = { k , l , k , l };
	}
	else {
		dx = { -1,-1,1,1 };
		dy = { -1,1,1,-1 };
		nums = { l, k , l ,k };
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < nums[i]; j++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			temp[nx][ny] = arr[x][y];
			x = nx;
			y = ny;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = temp[i][j];
		}
	}

}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	int x, y, m1, m2, m3, m4, dir;
	cin >> x >> y >> m1 >> m2 >> m3 >> m4 >> dir;

	Calc(x - 1, y - 1, m1, m2, dir);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}