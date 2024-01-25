#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

enum ELE {
	Water,
	Glacier
};

int arr[201][201];
queue<pair<int, int>> q;
bool visited[201][201];
int cnt, n ,m;

int e, l;

int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

bool Neibor(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (InRange(nx, ny) && visited[nx][ny]) {
			return true;
		}
	}

	return false;
}

bool CanGo(int x, int y) {
	return InRange(x, y) && arr[x][y] == Water && !visited[x][y];
}

void Initial() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 0;
		}
	}
}

void BFS() {
	Initial();

	q.push(make_pair(0, 0));
	visited[0][0] = true;


	while (!q.empty()) {
		pair<int, int> p = q.front();
		int x = p.first;
		int y = p.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (CanGo(nx, ny)) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
}

void Melt() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == Glacier && Neibor(i, j)) {
				arr[i][j] = Water;
				l++;
			}
		}
	}
}

void Calc() {
	e++;
	l = 0;

	BFS();

	Melt();
}

bool Calc2() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == Glacier) {
				return true;
			}
		}
	}

	return false;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	do {
		Calc();
	} while (Calc2());

	cout << e << " " << l;
}