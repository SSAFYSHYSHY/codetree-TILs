#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int n, r, c;
int arr[101][101];
vector<int> v;

bool InRange(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

bool Calc() {
	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };

	for (int i = 0; i < 4; i++) {
		int nx = r + dx[i];
		int ny = c + dy[i];

		if (InRange(nx, ny) && arr[nx][ny] > arr[r][c]) {
			r = nx;
			c = ny;
			return true;
		}
	}

	return false;
}

int main() {
	cin >> n >> r >> c;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	v.push_back(arr[r][c]);
	while (1) {
		bool flag = Calc();

		if(!flag) 
		{
			break;
		}

		v.push_back(arr[r][c]);
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}