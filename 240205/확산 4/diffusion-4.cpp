#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

queue<pair<int, int>> q;
bool visited[500][500] = {false,};
int arr[500][500];
int n, m, s;

void Initial() {
	//큐 초기화.
	while (!q.empty()) {
		q.pop();
	}

	//방문 초기화.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m && !visited[x][y];
}

void BFS() {
	int dx[] = { -1,1,0,0 };
	int dy[] = { 0,0,-1,1 };

	while (!q.empty()) {
		pair<int, int> p = q.front();
		int x = p.first;
		int y = p.second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (arr[nx][ny] == 1) {
				continue;
			}
			arr[nx][ny] = 2;


			if (InRange(nx, ny) && arr[nx][ny] == 1) {
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
}

void Change() {
	//0 -> 1, 나머지 0으로.

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				arr[i][j] = 1;
			}
			else {
				arr[i][j] = 0;
 			}
		}
	}
}

void Print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				cout << ".";
			}
			else {
				cout << "O";
			}
		}
		cout << "\n";
	}
}

int main() {
	cin >> n >> m >> s;

	//작업.
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < m; j++) {
			if (s[j] == '.') {
				arr[i][j] = 0;
			}
			else if (s[j] == 'O') {
				arr[i][j] = 1;
			}
		}
	}

	//시뮬 S 만큼 반복. 짝수면 답은 모두 같음, 1 이 찍힌 경우.
	if (s % 2 == 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << "O";
			}
			cout << "\n";
		}

		return 0;
	}
	else if (s == 1) {
		Print();
		return 0;
	}

	//
	for (int i = 3; i <= s; i+=2) {
		Initial();


		//BFS()연산.
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (arr[j][k] == 1 && !visited[j][k]) {
					visited[j][k] = true;
					q.push(make_pair(j, k));
					BFS();
				}
			}
		}

		//배열 변환.
		Change();
	}
	Print();

}