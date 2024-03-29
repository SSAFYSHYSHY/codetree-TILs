#include <iostream>
#include <algorithm>

using namespace std;

int n, m, t;
int arr[51][51];
int new_arr[51][51];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void Initial() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			new_arr[i][j] = 0;
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void Add(int x, int y) {
	int sum = 0;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (InRange(nx, ny) && arr[nx][ny] != -1) {
			new_arr[nx][ny] += (arr[x][y] / 5);
			sum += (arr[x][y] / 5);
		}
	}
	new_arr[x][y] = new_arr[x][y] + arr[x][y] - sum;
}

void Remove_up(int a) {
	//반시계 방향.
	int temp = new_arr[a][m - 1];
	for (int i = m; i >= 1; i--) {
		new_arr[a][i] = new_arr[a][i - 1];
	}
	new_arr[a][1] = 0;

	//위로 가는 방향.
	int temp2 = new_arr[0][m - 1];
	for (int i = 0; i < a - 1; i++) {
		new_arr[i][m - 1] = new_arr[i + 1][m - 1];
	}
	new_arr[a - 1][m - 1] = temp;

	//왼쪽으로 가는 방향.
	int temp3 = new_arr[0][0];
	for (int i = 0; i < m - 1; i++) {
		new_arr[0][i] = new_arr[0][i + 1];
	}
	new_arr[0][m - 2] = temp2;

	//아래로 가는 방향.
	for (int i = a; i > 0; i--) {
		new_arr[i][0] = new_arr[i - 1][0];
	}
	new_arr[1][0] = temp3;

	new_arr[a][0] = -1;
}

void Remove_down(int a) {
	//시계 방향.
	int temp = new_arr[a][m - 1];
	for (int i = m - 1; i >= 1; i--) {
		new_arr[a][i] = new_arr[a][i - 1];
	}
	new_arr[a][1] = 0;

	//14
	int temp2 = new_arr[n - 1][m - 1];

	for (int i = n - 1 ; i > a; i--) {
		new_arr[i][m - 1] = new_arr[i - 1][m - 1];
	}
	new_arr[a + 1][m - 1] = temp;

	int temp3 = new_arr[n - 1][0];
	for (int i = 0; i < m - 2; i++) {
		new_arr[n - 1][i] = new_arr[n - 1][i + 1];
	}
	new_arr[n - 1][m - 2] = temp2;

	
	for (int i = a; i < n - 1; i++) {
		new_arr[i][0] = new_arr[i + 1][0];
	}

	new_arr[n - 2][0] = temp3;
	new_arr[a][0] = -1;
}

int Sum() {
	int sum = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] > 0) {
				sum += arr[i][j];
			}
		}
	}

	return sum;
}

void Print() {
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << new_arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void Copy() {
	for(int i = 0; i < n ;i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = new_arr[i][j];
		}
	}
}

int main() {
	cin >> n >> m >> t;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	while (t--) {
		//먼지 확산.
		Initial();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {

				Add(i, j);
			}
		}

		//Print();

		//먼지 제거.
		for (int i = 0; i < n; i++) {
			if (arr[i][0] == -1 && arr[i+1][0] == -1) {
				Remove_up(i);

				Remove_down(i + 1);

				//Print();
			}
		}

		Copy();
	}

	int ans = Sum();

	cout << ans;
}