#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>

using namespace std;

int arr[16][16];

bool visited[16][16];
bool new_visited[16][16] = {false,};
int n, m, d, p;

int dx[] = {0,0,-1,-1,-1,0,1,1,1};
int dy[] = {0,1,1,0,-1,-1,-1,0,1};

void Initial() {
	for (int i = n - 2; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			visited[i][j] = true;
		}
	}
}

void Move(int d, int p) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			new_visited[i][j] = false;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) {
				int nx = (i + dx[d] * p + n * p) % n;
				int ny = (j + dy[d] * p + n * p) % n;

				new_visited[nx][ny] = true;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = new_visited[i][j];
		}
	}
}

void Grow() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) {
				arr[i][j]++;
			}
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

int Sum(int x, int y) {
	int d = 2;
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[d];
		int ny = y + dy[d];

		if (InRange(nx, ny) && arr[nx][ny] >= 1) {
			cnt++;
		}

		d += 2;
	}

	return cnt;
}

void Calc() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) {
				int cnt = Sum(i, j);
				arr[i][j] += cnt;
			}
		}
	}
}

void Remove() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j]) {
				visited[i][j] = false;
			}
			else if (arr[i][j] >= 2) {
				visited[i][j] = true;
				arr[i][j] -= 2;
			}
		}
	}

}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			visited[i][j] = false;
		}
	}

	Initial();

	while (m--) {
		//d, p 만큼 이동.
		cin >> d >> p;
		Move(d,p);

		Grow();

		//대각선의 합을 구하기.
		Calc();

		//2 이상 제거하기.
		Remove();
	}

	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			sum += arr[i][j];
		}
	}

	cout << sum;
}