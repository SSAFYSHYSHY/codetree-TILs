#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, k,x,y, ax, ay, mini = 21e8;
queue<pair<int, int>> q;
int arr[101][101];
int ans[101][101];
bool visited[101][101];

void Push(int x, int y, int num) {
	visited[x][y] = true;
	ans[x][y] = num;
	q.push(make_pair(x, y));
}

void Initial() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ans[i][j] = 0;
			visited[i][j] = false;
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void BFS() {
	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };

	Push(x, y, 0);
	while (!q.empty()) {
		pair<int, int> p = q.front();
		int x = p.first;
		int y = p.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == 0) {
				Push(nx, ny, ans[x][y] + 1);
			}
		} 
	}

	if (arr[ax][ay] == 0 && ans[ax][ay]) {
		mini = min(mini, ans[ax][ay]);
	}

}

void Calc(int num) {
	if (num == k) {
		Initial();
		BFS();

		//for (int i = 0; i < n; i++) {
		//	for (int j = 0; j < n; j++) {
		//		cout << ans[i][j] << " ";
		//	}
		//	cout << "\n";
		//}
		//cout << "\n\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1) {
				arr[i][j] = 0;
				Calc(num + 1);
				arr[i][j] = 1;
			}
		}
	}
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> x >> y;
	cin >> ax >> ay;

	x -= 1;
	y -= 1;
	ax -= 1;
	ay -= 1;

	//백트래킹.
	Calc(0);

	if (mini == 21e8) {
		cout << -1;
	}
	else {
		cout << mini;
	}

}