#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n, cnt = 1, cnt1= 1, one = 0, two = 0, maxi = 0;
char crr[101][101];
char crr1[101][101];

bool visited[101][101] = {false,};

int arr[101][101];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void Initial() {
	cnt = 1;
	maxi = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
			arr[i][j] = 0;
		}
	}
}

int FindMax() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] > maxi) {
				maxi = arr[i][j];
			}
		}
	}

	return maxi;
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void DFS(int x, int y, int flag) {
	arr[x][y] = cnt;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (flag == 1) {
			if (InRange(nx, ny) && !visited[nx][ny] && crr[nx][ny] == crr[x][y]) {
				//색맹이 아닌 사람의 배열.
				arr[nx][ny] = cnt;
				visited[nx][ny] = true;
				DFS(nx, ny, 1);
			}
		}
		else {
			if (InRange(nx, ny) && !visited[nx][ny] && crr1[nx][ny] == crr1[x][y]) {
				//색맹이 아닌 사람의 배열.
				arr[nx][ny] = cnt;
				visited[nx][ny] = true;
				DFS(nx, ny, 2);
			}
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			crr[i][j] = s[j];

			if (s[j] == 'R' || s[j] == 'G') {
				crr1[i][j] = 'O';
			}
		}
	}

	//색맹이 아닌 겨우.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				visited[i][j] = true;
				DFS(i, j, 1);
				cnt++;
			}
		}
	}
	one = FindMax();
	//cout  << "\n\n" << one <<"\n\n";

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << "\n";

	Initial();

	//색명인 겨우.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				visited[i][j] = true;
				DFS(i, j, 2);
				cnt++;
			}
		}
	}
	two = FindMax();

	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << arr[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << "\n";

	cout << one << " " << two;
}