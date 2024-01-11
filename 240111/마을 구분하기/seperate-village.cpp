#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[26][26];
int new_arr[26][26];
bool visited[26][26] = {false,};

vector<int> v;

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y) {
	if (!InRange(x, y)) {
		return false;
	}
	if (visited[x][y] == true || arr[x][y] == 0) {
		return false;
	}

	return true;
}

void DFS(int x, int y, int num) {
	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (CanGo(nx, ny)) {
			visited[nx][ny] = true;
			new_arr[nx][ny] = num;
			DFS(nx, ny, num);
		}
	}
}

void Calc2(int num) {

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (new_arr[i][j] == num) {
				cnt++;
			}
		}
	}

	v.push_back(cnt);
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	int cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			
			if (arr[i][j] && visited[i][j] == false) {
				//DFS 연산.
				visited[i][j] = true;
				new_arr[i][j] = cnt;
				DFS(i, j, cnt);

				//DFS 연산 끝 해당 숫자 넘버들 합 연산.
				Calc2(cnt);
				cnt++;
				
			}
		}
	}

	sort(v.begin(), v.end());

	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}