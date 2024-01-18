#include <iostream>
#include <queue>

using namespace std;

queue<int> q;
int n, ans =0;
bool visited[1000001];
int arr[1000001];

bool InRange(int x) {
	return 1 <= x && x <= 1000001;
}

void BFS() {
	int nx = 0;

	while (!q.empty()) {
		int na = q.front();
		q.pop();

		if (na == 1) {
			ans = arr[1];
			return;
		}

		//-1
		if (InRange(na - 1) && !visited[na - 1]) {
			visited[na-1] = true;
			q.push(na-1);
			arr[na - 1] = arr[na] + 1;
		}

		// +1
		if (InRange(na + 1) && !visited[na + 1]) {
			visited[na+1] = true;
			q.push(na+1);
			arr[na + 1] = arr[na] + 1;
		}

		// / 2
		if (na % 2 == 0 && !visited[na/2]) {
			visited[na/2] = true;
			q.push(na/2);
			arr[na / 2] = arr[na] + 1;
		}

		// / 3
		if (na % 3 == 0 && !visited[na/3]) {
			visited[na/3] = true;
			q.push(na/3);
			arr[na / 3] = arr[na] + 1;
		}

	}
}

int main() {
	cin >> n;

	q.push(n);
	visited[n] = true;

	BFS();

	cout << ans;
}