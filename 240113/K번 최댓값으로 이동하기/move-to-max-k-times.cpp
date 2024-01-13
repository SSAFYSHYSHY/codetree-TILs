#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>
#define NOT make_pair(-1,-1)

using namespace std;

int n, k;
queue<pair<int, int>> q;
pair<int, int> curr;
int arr[101][101];
bool visited[101][101];

void Initial() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y, int num) {
	return InRange(x, y) && !visited[x][y] && arr[x][y] < num;
}

void BFS() {
	int dx[] = {0,1,0,-1};
	int dy[] = {1,0,-1,0};

	int x, y;
	tie(x, y) = curr;
	visited[x][y] = true;
	q.push(curr);

	int num = arr[x][y];

	while (!q.empty()) {
		pair<int, int> p = q.front();
		int cx, cy;
		tie(cx, cy) = p;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (CanGo(nx, ny, num)) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}

}

bool Calc2(pair<int, int> p, pair<int, int> p1) {
	if (p == make_pair(-1, -1)) {
		return true;
	}

	int bx, by;
	tie(bx, by) = p;

	int nx, ny;
	tie(nx, ny) = p1;

	return make_tuple(arr[nx][ny], -nx, -ny) > make_tuple(arr[bx][by], -bx, -by);
}

bool Calc() {
	//초기화.
	Initial();

	//1, 모든 위치 초기화.
	BFS();

	//2. 방문해서 가장 우선순위가 높은 곳 
	pair<int, int> pp = { -1,-1 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] || make_pair(i, j) == curr) {
				continue;
			}

			pair<int, int> pp2 = make_pair(i, j);
			if (Calc2(pp, pp2)) {
				pp = pp2;
			}
		}
	}

	//3 위치 이동.
	if (pp == make_pair(-1,-1)) {
		return false;
	}
	else {
		curr = pp;
		return true;
	}

}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	int x, y;
	cin >> x >> y;

	x -= 1;
	y -= 1;

	curr = make_pair(x, y);

	while (k--) {
		bool flag = Calc();

		if (!flag) {
			break;
		}
	}

	int ax, ay;
	tie(ax, ay) = curr;
	cout << ax + 1<< " " << ay + 1;
}