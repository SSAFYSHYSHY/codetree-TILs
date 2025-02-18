#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m, ans = 0;
int arr[9][9];
int new_arr[9][9];
bool visited[9][9] = { false, };
bool back_visited[65] = {false,};

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

struct Node {
	int x, y;
};

vector<Node> v, v1;

void Input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];

			if(arr[i][j] == 0) {
				v.push_back({ i,j });
			}
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void BFS(int x, int y) {
	queue<Node> q;
	q.push({ x,y });
	visited[x][y] = true;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && new_arr[nx][ny] == 0) {
				q.push({ nx,ny });
				visited[nx][ny] = true;
				new_arr[nx][ny] = 2;
			}
		}
	}
}

//BFS 시작.
int Simul() {
	//visited 초기화.
	memset(visited, false, sizeof(visited));
	//copy 원본.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			new_arr[i][j] = arr[i][j];
		}
	}

	//v1 의 좌표들을 1로 바꾼다.
	for (int i = 0; i < v1.size(); i++) {
		new_arr[v1[i].x][v1[i].y] = 1;
	}



	//2 의 위치에 대해서 BFS 진행. 2 로 바꾸지는 않고 visited로만 연산.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && new_arr[i][j] == 2) {
				BFS(i, j);
			}
		}
	}


	//ans를 누적해서 반환.
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (new_arr[i][j] == 0) {
				cnt++;
			}
		}
	}

	return cnt;
}

void Back(int now, int idx) {
	if (now == 3) {
		ans = max(ans, Simul());
		return;
	}

	for (int i = idx + 1; i < v.size(); i++) {
		if (!back_visited[i]) {
			back_visited[i] = true;
			v1.push_back({v[i]});
			Back(now + 1, i);
			v1.pop_back();
			back_visited[i] = false;
		}
	}
}

int main() {
	Input();

	Back(0, -1);

	cout << ans;
}