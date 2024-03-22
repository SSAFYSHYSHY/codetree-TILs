#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <time.h>

using namespace std;

int n, m, max_ans = 0, ans = 0, cnt = 1;
int arr[501][501];
int score[501][501];

bool visited[501][501] = { false, };

queue<pair<int, int>> q;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

bool Flag() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) {
				return false;
			}
		}
	}

	return true;
}

bool Near(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (InRange(nx, ny) && arr[nx][ny] == 1) {
			return true;
		}
	}

	return false;
}

void Initial() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}
}

int Calc(int x, int y) {
	//초기화.
	int cnt = 1;
	q.push(make_pair(x, y));
	visited[x][y] = true;

	while (!q.empty()) {
		pair<int, int> p = q.front();
		int x = p.first;
		int y = p.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == 1) {
				cnt++;
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}

	return cnt;
}

int main() {
	clock_t start, finish;
	double duration;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	start = clock();

	//만약 모든 좌표가 1인 경우에는 하나를 0으로 바꾸고 continue.
	int maxj = 0;
	if (Flag()) {
		arr[0][0] = 0;

		Initial();
		maxj = Calc(0, 1);
		ans = max(ans, maxj);

		cout << ans;
		return 0;
	}

	int maxi = 0;
	//만약 0을 발견 했을때 근처에 1이 있는가.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//0 이고 근처에 1이 있으면.
			if (arr[i][j] == 0 && Near(i, j)) {
				//해당 배열을 1로 바꿔주고.
				arr[i][j] = 1;

				//방문과 점수 초기화.
				Initial();

				//해당 부분들만 BFS() 순회.
				maxi = Calc(i,j);
				ans = max(ans, maxi);

				//완료되었으면 다시 돌려내기.
				arr[i][j] = 0;
			}
		}
	}

	finish = clock();

	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	//cout << duration << "초 \n";

	cout << ans;
}