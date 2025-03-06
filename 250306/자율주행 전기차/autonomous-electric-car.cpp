#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>

using namespace std;

struct Node {
	int x, y, dist, fuel;
};

struct Customer {
	int sx, sy, ex, ey;
};

int arr[21][21];
int new_arr[21][21];
bool visited[21][21] = { false, };
bool customer_visited[401] = { false, };
int n, m, c;
int s_x, s_y;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

Customer customer[401];

void Input() {
	cin >> n >> m >> c;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 1) arr[i][j] = -1;
		}
	}

	cin >> s_x >> s_y;

	for (int i = 1; i <= m; i++) {
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;

		arr[sx][sy] = i;

		customer[i] = { sx,sy,ex,ey };
		customer_visited[i] = false;
	}
}

bool InRange(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

//가장 최단거리 짧은 곳, 여러개면 x 좌표가 작은 곳, 그 마저도 같다면 y 좌표가 작은 곳.
bool cmp(Node a, Node b) {
	if (a.dist != b.dist) return a.dist < b.dist;
	if (a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

int Find_BFS(int x, int y, int now_dist, int now_fuel) {
	vector<Node> v;
	//x,y,이동 거리. 남은 연료.
	queue<Node> q;
	q.push({ x,y, 0, now_fuel});
	visited[x][y] = true;

	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int dist = q.front().dist;
		int fuel = q.front().fuel;
		q.pop();

		if (arr[cx][cy] > 0 && !customer_visited[arr[cx][cy]]) {
			v.push_back({ cx,cy,dist});
		}

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] != -1) {
				q.push({ nx,ny,dist + 1 , fuel-1});
				visited[nx][ny] = true;
			}
		}
	}

	//아무 승객도 못 찾았으면.
	if (v.empty()) {
		return -1;
	}

	sort(v.begin(), v.end(), cmp);

	//idx 값을 반환, 최초 거리에 대해서 연료 소모값 반환.
	c -= v[0].dist;
	customer_visited[arr[v[0].x][v[0].y]] = true;

	return arr[v[0].x][v[0].y];
}

int BFS2(int x, int y, int ex, int ey, int now_fuel) {
	memset(visited, false, sizeof(visited));
	queue<Node> q;
	q.push({ x, y, 0, now_fuel });
	visited[x][y] = true;


	while (!q.empty()) {
		int cx = q.front().x;
		int cy = q.front().y;
		int dist = q.front().dist;
		int now_fuel = q.front().fuel;
		q.pop();

		if (cx == ex && cy == ey) {

			if (now_fuel < 0) {
				return -1;
			}
			else {
				now_fuel += (dist * 2);
				return now_fuel;
			}
		}

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];  // 잘못된 x, y 참조 수정
			int ny = cy + dy[i];

			if (InRange(nx, ny) && arr[nx][ny] != -1 && !visited[nx][ny]) {
				q.push({ nx, ny, dist + 1 , now_fuel - 1});
				visited[nx][ny] = true;
			}
		}
	}
}


int main() {
	Input();

	for (int i = 0; i < m; i++) {

		memset(visited, false, sizeof(visited));
		int idx;
		//가장 가까운 거리의 좌표와 해당 idx 색출.
		idx = Find_BFS(s_x, s_y, 0, c);
		customer_visited[idx] = true;

		if (idx == -1) {
			cout << -1;
			return 0;
		}

		//가까운 위치에서 cusotmer의 idx의 값에 대해서 출구 값.
		//연료 값 갱신.

		c = BFS2(customer[idx].sx, customer[idx].sy, customer[idx].ex, customer[idx].ey, c);
		s_x = customer[idx].ex;
		s_y = customer[idx].ey;

		if (c == -1) {
			cout << -1;
			return 0;
		}
	}
	
	cout << c;
}
