#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int arr[51][51];
int arr2[51][51];
bool visited[51][51] = { false, };

vector<pair<int, int>> v;
vector<int> v1;
queue<pair<int, int>> q;

int ans = INT_MAX;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void Initial() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
			arr2[i][j] = 0;
		}
	}
}

void Hospital() {
	for (int i = 0; i < v1.size(); i++) {
		int idx = v1[i];
		int x = v[idx].first;
		int y = v[idx].second;
		arr2[x][y] = 1;
	}
}

void Enqueue() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr2[i][j] == 1 && arr[i][j] == 2) {
				q.push(make_pair(i, j));
				visited[i][j] = true;
			}
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}


int BFS() {
	//초기화.
	Initial();

	//병원 설정.
	Hospital();

	//q 설정.
	Enqueue();

	while (!q.empty()) {
		pair<int, int> p = q.front();
		int x = p.first;
		int y = p.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == 0) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
				arr2[nx][ny] = arr2[x][y] + 1;
			}
			else if (InRange(nx, ny) && !visited[nx][ny] && (arr[nx][ny] == 2 && arr2[nx][ny] == 0)) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
				arr2[nx][ny] = arr2[x][y];
			}
		}
	}

	//cout << "\n";
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << arr2[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << "\n\n";

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (cnt < arr2[i][j]) {
				cnt = arr2[i][j];
			}
		}
	}

	return cnt;
}


void Calc(int curr_idx, int cnt) {
	if (cnt == m) {
		ans = min(ans, BFS());
		return;
	}

	if (curr_idx == (int)v.size()) return;

	//idx 배열.
	v1.push_back(curr_idx);
	Calc(curr_idx + 1, cnt + 1);
	v1.pop_back();

	Calc(curr_idx + 1, cnt);
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];

			if (arr[i][j] == 2) {
				v.push_back(make_pair(i, j));
			}
		}
	}

	//idx, cnt;
	Calc(0, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr2[i][j] == 0 && arr[i][j] == 0) {
				cout << -1;
				return 0;
			}
		}
	}

	cout << ans - 1;
}