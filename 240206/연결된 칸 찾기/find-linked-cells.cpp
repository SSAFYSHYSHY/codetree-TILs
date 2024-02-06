#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[26][26];
int n, cnt =1;
bool visited[26][26] = { false, };
vector<int> v;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n && !visited[x][y] && arr[x][y] != 0;
}

int DFS(int x, int y) {

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (InRange(nx, ny)) {
			cnt += 1;
			visited[nx][ny] = true;
			DFS(nx, ny);
		}
	}

	return cnt;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] && !visited[i][j]) {
				visited[i][j] = true;
				int num = DFS(i, j);
				v.push_back(num);
				cnt = 1;
			}
		}
	}

	cout << v.size() << "\n";

	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}