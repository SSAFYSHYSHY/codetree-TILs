#include <iostream>
#include <queue>

using namespace std;

int arr[101][101];
int new_arr[101][101];
bool visited[101][101];
int n, ans;
queue<pair<int, int>> q;
int ss, sy, as, ay;

bool CanGo(int x, int y) {
	return 0 < x && x <= n && 0 < y && y <= n;
}

void Calc(int x, int y, int num) {
	new_arr[x][y] = num;
	visited[x][y] = true;
	q.push(make_pair(x, y));
}

void BFS() {
	int dx[] = {-1,-2,-2,-1,1,2,2,1};
	int dy[] = {-2,-1,1,2,-2,-1,1,2};

	while (!q.empty()) {
		pair<int, int> p = q.front();
		int x = p.first;
		int y = p.second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (CanGo(nx, ny) && !visited[nx][ny]) {
				Calc(nx, ny, new_arr[x][y] + 1);
			}
		}
	}
}

int main() {
	cin >> n;
	cin >> ss >> sy >> as >> ay;

	q.push(make_pair(ss, sy));
	new_arr[ss][sy] = 0;
	visited[ss][sy] = true;

	BFS();
	if(ss == sy && as == ay) {
		cout << 0;
		return 0;
	}

	if (new_arr[as][ay] > 0) {
		cout << new_arr[as][ay];
	}
	else {
		cout << -1;
	}
}