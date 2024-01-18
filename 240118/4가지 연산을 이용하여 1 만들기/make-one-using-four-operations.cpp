#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, mini = 21e8, cnt = 0;
queue<int> q;
bool visited[1000001];
int arr[1000001];
int new_arr[1000001];

bool InRange(int x) {
	return 0 <= x && x <= n;
}

void BFS() {
	while (!q.empty()) {
		int a = q.front();
		int dx[] = { -1, 1 , a*2, a*3 };
		q.pop();

		for (int i = 0; i < 4; i++) {
			int na = a + dx[i];

			if (InRange(na) && !visited[na]) {
				new_arr[na] = new_arr[a] + 1;
				visited[na] = true;
				q.push(na);
			}
		}

	}
}

int main() {
	cin >> n;

	for (int i = 0; i <= n; i++) {
		arr[i] = i;
	}

	new_arr[1] = 1;
	visited[arr[1]] = true;
	q.push(arr[1]);
	BFS();

	cout << new_arr[n-1];
}