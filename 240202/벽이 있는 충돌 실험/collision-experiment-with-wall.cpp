#include <iostream>

using namespace std;

int arr[51][51];

int ball[51][51];
int new_ball[51][51];
bool visited[51][51] = {false,};
int T, n, m, ans = 21e8;

int dx[] = {0,-1,1,0,0};
int dy[] = {0,0,0,-1,1};

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void Calc(int x, int y, int dir) {
	int nx = x + dx[dir];
	int ny = y + dy[dir];

	if (InRange(nx, ny)) {
		new_ball[nx][ny]++;
		arr[nx][ny] = dir;
	}
	else {
		if (dir == 1) {
			dir = 2;
		}
		else if (dir == 2) {
			dir = 1;
		}
		else if (dir == 3) {
			dir = 4;
		}
		else if (dir == 4) {
			dir = 3;
		}

		nx = x + dx[dir];
		ny = y + dy[dir];
		arr[nx][ny] = dir;
		new_ball[nx][ny]++;
	}
	visited[nx][ny] = true;

	arr[x][y] = 0;
}

void MoveAll() {
	//new_ball 초기화.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			new_ball[i][j] = 0;
			visited[i][j] = false;
		}
	}

	//이동.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] && !visited[i][j]) {
				Calc(i, j, arr[i][j]);
			}
		}
	}

	//복사.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ball[i][j] = new_ball[i][j];
		}
	}

	//cout << "\nMoved Ball \n";
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << ball[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << "\n";

	//cout << "\nMoved Arr \n";
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << "\n";
}

int RemoveAll() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ball[i][j] >= 2) {
				ball[i][j] = 0;
				arr[i][j] = 0;
			}
		}
	}

	//cout << "\nRemoved Moved Ball \n";
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << ball[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << "\n";

	//cout << "\nRemoved Moved Arr \n";
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << "\n";

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ball[i][j]) {
				cnt++;
			}
		}
	}

	return cnt;
}

void PrintAll() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (ball[i][j]) {
				cnt++;
			}
		}
	}

	cout << cnt << "\n";
}

void Initial() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ball[i][j] = 0;
			arr[i][j] = 0;
			visited[i][j] = false;
		}
	}

	for (int i = 0; i < m; i++) {
		int x, y, idx = 0;
		char dir;

		cin >> x >> y >> dir;

		x -= 1;
		y -= 1;

		if (dir == 'U') {
			idx = 1;
		}
		else if (dir == 'D') {
			idx = 2;
		}
		else if (dir == 'L') {
			idx = 3;
		}
		else if (dir == 'R') {
			idx = 4;
		}

		ball[x][y]++;
		arr[x][y] = idx;

		//cout << ball[x][y] << "\n";
	}
}

int main() {
	cin >> T;

	while (T--) {
		//구슬 위치, 입력 및 초기화.
		Initial();

		for (int i = 1; i <= 2 * n; i++) {
			//구슬 이동.
			MoveAll();

			//2 이상의 구슬들 모두 삭제와 갯수.
			RemoveAll();
		}

		//출력.
		PrintAll();
	}
}