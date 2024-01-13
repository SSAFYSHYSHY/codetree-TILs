#include <iostream>
#include <queue>

using namespace std;

int n, m;
int arr[101][101];
int new_arr[101][101];
bool visited[101][101];
queue<pair<int, int>> q;

bool CanGo(int x, int y) {
	return (0 <= x && x < n && 0 <= y && y < m) && (arr[x][y] == 1);
}

void Calc(int x, int y, int num) {
	new_arr[x][y] = num;
	visited[x][y] = true;
	q.push(make_pair(x, y));
}

void BFS() {
	int dx[] = {1,-1,0,0};
	int dy[] = { 0,0,-1,1 };

	while (!q.empty()) {
		pair<int, int> p = q.front();
		int x = p.first;
		int y = p.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (CanGo(nx, ny) && !visited[nx][ny]) {
				Calc(nx, ny, new_arr[x][y]+1);
			}
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	q.push(make_pair(0, 0));
	new_arr[0][0] = 0;
	visited[0][0] = true;

	BFS();
    if(new_arr[n-1][m-1] == 0) {
        cout << -1;
    }
    else {
	    cout << new_arr[n - 1][m - 1];
    }
}