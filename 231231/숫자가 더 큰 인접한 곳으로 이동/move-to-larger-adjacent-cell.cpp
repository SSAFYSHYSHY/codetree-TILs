#include <iostream>
#include <vector>

using namespace std;

int n, x, y;
int arr[101][101];
vector<int> v;

bool InRange(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

bool CanGo(int x, int y, int num) {
	return InRange(x, y) && arr[x][y] > num;
}

bool Calc() {
	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (CanGo(nx, ny, arr[x][y])) {
			x = nx;
			y = ny;
			return true;
		}
	}

	return false;
}

int main() {
	cin >> n >> x >> y;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	v.push_back(arr[x][y]);

	while (1) {
		bool flag = Calc();

		if (!flag) {
			break;
		}

		v.push_back(arr[x][y]);
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}