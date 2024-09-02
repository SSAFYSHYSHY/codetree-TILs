#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, l, r, ans= 0;
int arr[51][51];
int new_arr[51][51];
bool visited[51][51] = { false, };

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool Flag() {
	
	int ansi = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (new_arr[i][j] > ansi) {
				ansi = new_arr[i][j];
			}
		}
	}

	if (ansi == (n * n) - 1) {
		return false;
	}

	return true;
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void BFS(int x, int y, int num) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visited[x][y] = true;
	new_arr[x][y] = num;
	int sum = arr[x][y];
	int cnt = 1;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && (l <= abs(arr[cx][cy] - arr[nx][ny]) && abs(arr[cx][cy] - arr[nx][ny]) <= r)) {
				q.push(make_pair(nx, ny));
				sum += arr[nx][ny];
				visited[nx][ny] = true;
				new_arr[nx][ny] = num;
				cnt++;
			}
		}
	}

	int avg = sum / cnt;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (new_arr[i][j] == num) {
				arr[i][j] = avg;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> l >> r;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	while (Flag()) {
		memset(visited, false, sizeof(visited));
		memset(new_arr, -1, sizeof(new_arr));

		int num = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					BFS(i, j, num);
					num++;
				}
			}
		}

		ans++;
	}

	ans -= 1;
	if(ans <= 0){
		cout << 0;
	}
	else {
		cout << ans;
	}
}