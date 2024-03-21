#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, cnt =0;
int arr[13][13];

bool visited[13][13] = { false, };

vector<int> v;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void Initial() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = false;
		}
	}
}

bool Flag() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1) {
				return true;
			}
		}
	}

	return false;
}

void Print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void DFS(int x, int y) {

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (InRange(nx, ny) && !visited[nx][ny]) {
			visited[nx][ny] = true;

			if (arr[nx][ny] == 1) {
				arr[nx][ny] = 2;
			}
			if(arr[nx][ny] == 0) {
				DFS(nx, ny);
			}
		}
	}
}

void DFS1(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (InRange(nx, ny) && !visited[nx][ny]) {
			visited[nx][ny] = true;

			if (arr[nx][ny] == 1) {
				arr[nx][ny] = 1;
				DFS1(nx, ny);
			}
			if (arr[nx][ny] == 0) {
				arr[nx][ny] = 0;
			}
		}

	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	while (Flag()) {
		Initial();

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				//겉 0 에서 1 들을 순회.
				if (arr[i][j] == 0 && !visited[i][j]) {
					visited[i][j] = true;
					DFS(i, j);
				}

				//속 1에서 0들을 찾으면 true로.
				if (arr[i][j] == 1 && !visited[i][j]) {
					visited[i][j] = true;
					DFS1(i, j);
				}
			}
		}

		int sum = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 2) {
					arr[i][j] = 0;
				}
				if (arr[i][j] == 1) {
					sum++;
				}
			}
		}

		v.push_back(sum);

		// Print();
	}

	cout << v.size() << "\n" << v[v.size() - 2] << " ";


}