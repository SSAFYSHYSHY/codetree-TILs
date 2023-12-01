#include <iostream>

using namespace std;

int n, m;
int arr[101][101] = { 0, };
int temp[101][101] = { 0 , };
int q;

int dx[] = { 0, -1,1,0,0 };
int dy[] = { 0, 0,0,-1,1 };

bool InRange(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m;
}

int Calc3(int x, int y) {
	int sum = 0, cnt = 0;

	for (int i = 0; i < 5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (InRange(nx, ny)) {
			cnt++;
			sum += arr[nx][ny];
		}
	}

	return sum / cnt;
}

void Calc2(int x, int y, int x1, int y1) {
	
	for (int i = x; i <= x1; i++) {
		for (int j = y; j <= y1; j++) {
			temp[i][j] = Calc3(i, j);
		}
	}

	for (int i = x; i <= x1; i++) {
		for (int j = y; j <= y1; j++) {
			arr[i][j] = temp[i][j];
		}
	}
}

void Calc(int i, int j, int k, int l) {

	// 오른
	int temp1 = arr[i][l];

	for (int a = l; a >= j + 1; a--) {
		arr[i][a] = arr[i][a - 1];

	}

	arr[i][j] = arr[i + 1][j];


	// 아래
	int temp2 = arr[k][l];

	for (int a = k; a >= i + 2; a--) {
		arr[a][l] = arr[a - 1][l];

	}

	arr[i + 1][l] = temp1;

	//왼쪽

	int temp3 = arr[k][j];

	for (int a = j; a <= l - 2; a++) {
		arr[k][a] = arr[k][a + 1];

	}
	arr[k][l - 1] = temp2;

	//위쪽

	for (int a = i + 1; a <= k - 2; a++) {
		arr[a][j] = arr[a + 1][j];

	}

	arr[k - 1][j] = temp3;
}

int main() {
	cin >> n >> m >> q;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			temp[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < q; i++) {
		int x1, y1, x2, y2;

		cin >> x1 >> y1 >> x2 >> y2;

		Calc(x1, y1, x2, y2);
		Calc2(x1, y1, x2, y2);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}