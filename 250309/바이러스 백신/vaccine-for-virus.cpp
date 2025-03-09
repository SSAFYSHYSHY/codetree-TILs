#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int arr[51][51];
bool visited[51][51];

struct Node {
	int x, y, dict;
};

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

vector<pair<int, int>> v;
vector<int> v1;
int ans = 21e8;
bool back_visited[11] = {false,};

void Input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 2) {
				v.push_back({ i,j });
			}
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

int BFS() {
	queue<Node> q;
	memset(visited, false, sizeof(visited));

	int maxi = 0;
	//Back의 결과 q에 각각 넣고 BFS 이동.
	for (int i = 0; i < v1.size(); i++) {
		int x = v[v1[i]].first;
		int y = v[v1[i]].second;
		q.push({ x,y,0 });
		visited[x][y] = true;
	}

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dict = q.front().dict;
		q.pop();

		maxi = max(maxi, dict);

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			//범위 안에 방문하지 않고 벽이 아니면.
			if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] != 1) {
				//그냥 바이러스인 경우 +1
				if (arr[nx][ny] == 0) {
					q.push({ nx,ny, dict + 1 });
					visited[nx][ny] = true;
				}
				//만약 병원을 마주한 경우.
				else if (arr[nx][ny] == 2) {
					q.push({ nx,ny,dict });
					visited[nx][ny] = true;
				}

			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0 && !visited[i][j]) {
				return 21e8;
			}
		}
	}

	return maxi;
}

void Back(int now, int cnt) {
	if (cnt == m) {
		ans = min(ans, BFS());
		return;
	}

	for (int i = now; i < v.size(); i++) {
		if (!back_visited[i]) {
			back_visited[i] = true;
			v1.push_back(i);
			Back(i + 1, cnt + 1);
			v1.pop_back();
			back_visited[i] = false;
		}
	}
}


int main() {
	Input();

	//now, cnt
	Back(0, 0);

	if (ans == 21e8) {
		cout << -1;
	}
	else {
		cout << ans;
	}
}