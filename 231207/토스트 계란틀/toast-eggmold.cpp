#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int n, L, R;

vector<pair<int, int>> egg;
queue<pair<int, int>> q;

int arr[51][51];
bool visited[51][51];

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

bool CanGo(int x, int y, int curr) {
	if (!InRange(x, y)) return false;

	int diff = abs(arr[x][y] - curr);

	return !visited[x][y] && L <= diff && diff <= R;
}

void BFS() {
	int dx[] = { -1,0,1,0 };
	int dy[] = { 0,-1,0,1 };

	while (!q.empty()) {
		pair<int, int> curr = q.front();
		int curr_x, curr_y;
		tie(curr_x, curr_y) = curr;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curr_x + dx[i];
			int ny = curr_y + dy[i];

			if (CanGo(nx, ny, arr[nx][ny])) {
				q.push(make_pair(nx, ny));
				egg.push_back(make_pair(nx, ny));
				//만약 가중치가 존재한다면 해당 값을 새로운 배열에 누적.
				visited[nx][ny] = true;
			}
		}
	}
} 

void Calc2() {
	int sum = 0;
	for (int i = 0; i < egg.size(); i++) {
		int x, y;
		tie(x, y) = egg[i];
		sum += arr[x][y];
	}

	for (int i = 0; i < egg.size(); i++) {
		int x, y;
		tie(x, y) = egg[i];
		arr[x][y] = sum / egg.size();
	}
}

bool Calc() {
	Initial();
	bool flag = false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				egg.clear();

				egg.push_back(make_pair(i, j));
				q.push(make_pair(i, j));
				BFS();


				if (q.size() > 1) {
					flag = true;
				}

				Calc2();
			}
		}
	}

	return flag;
}

int main() {
	cin >> n >> L >> R;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	int cnt = 0;
	while (1) {
		bool flag = Calc();
		if (!flag) {
			break;
		}
		cnt++;
	}

	cout << cnt;
}