#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;


int n , m, ans = 0;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

struct Node {
	int x, y, dist;
};

int arr[21][21];
int new_arr[21][21];
bool visited[21][21] = { false, };
vector<Node> v;

void Input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void BFS(int x, int y, int num) {
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({ x,y });
	int cnt = 1;
	visited[x][y] = true;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && (arr[nx][ny] == num || arr[nx][ny] == 0)) {
				visited[nx][ny] = true;
				q.push({ nx,ny });
				cnt++;
			}
		}
	}

	if (cnt < 2) return;

	v.push_back({ x,y,cnt });
}

bool cmp(Node a, Node b) {
	if (a.dist != b.dist) return a.dist > b.dist;
	if (a.x != b.x) return a.x > b.x;
	return a.y > b.y;
}

void Find() {
	memset(visited, false, sizeof(visited));

	//찾으면 합들을 v에 누적.
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] > 0 && !visited[i][j]) {
				BFS(i, j, arr[i][j]);

			}
		}
	}

	sort(v.begin(), v.end(), cmp);
}

int BFS2(int x, int y, int num) {
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;
	int size = 1;

	arr[x][y] = -2;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		arr[cx][cy] = -2;

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && (arr[nx][ny] == 0 || arr[nx][ny] == num)) {
				q.push({ nx,ny });
				visited[nx][ny] = true;
				size++;
			}
		}
	}

	return size * size;
}

void Gravity() {
	//memset(new_arr, -2, sizeof(new_arr));

	for (int j = 0; j < n; j++) {
		int temp = n - 1;

		for (int i = n - 1; i >= 0; i--) {
			if (arr[i][j] == -1) {
				temp = i - 1;
			}
			else if (arr[i][j] != -2) {
				swap(arr[i][j], arr[temp--][j]);
			}
		}
	}
}

void Rotate() {
	memset(new_arr, -2, sizeof(new_arr));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			new_arr[i][j] = arr[j][n - i -1];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = new_arr[i][j];
		}
	}
}

void Print() {
	cout << "\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";

}

int main() {
	Input();

	while (1) {
		//가장 큰 폭탄 찾기.
		//v 가 비어있다면 skip

		//큰 폭탄들 좌표 정렬.
		//같은 크기의 폭탄이 여러개라면,
		//그 중에 행이 가장 큰 폭탄,
		//그 중에 열이 가장 작은 폭탄.
		//기 준점까지 동일하다면, 그 중에 열이 가장 작은 폭탄.
		Find();

		if (v.empty()) {
			break;
		}

		//폭탄 제거.
		ans += BFS2(v[0].x, v[0].y, arr[v[0].x][v[0].y]);

		//중력.
		Gravity();

		//반시계 회전.
		Rotate();

		//중력.
		Gravity();

		v.clear();
	}

	cout << ans;
}