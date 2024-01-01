#include <iostream>
#include <vector>

using namespace std;

int arr[101][101];
int temp[101][101];
int n,r, c, m1, m2, m3, m4, dir;

void Calc(int x, int y, int k, int l, int k1, int l1, int dir) {
	vector<int> dx, dy, d;

	
	if (dir == 0) {
		dx = { -1,-1,1,1 };
		dy = { 1,-1,-1,1 };
		d = { k,l,k1,l1 };
	}
	else {
		dx = { -1,-1,1,1 };
		dy = { -1,1,1,-1 };
		d = { l1,k1,l,k };
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = arr[i][j];
		}
	}

	//직사각형.
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < d[i]; j++) {
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

	cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;

	int x = r - 1;
	int y = c - 1;

	Calc(x, y, m1, m2, m3,m4, dir);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}