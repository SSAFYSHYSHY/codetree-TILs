#include <iostream>
#include <vector>

using namespace std;

vector<int> v[101];
bool visited[101] = {false,};
int n, m, cnt = 0;

void DFS(int now) {
	visited[now] = true;

	for (int i = 0; i < v[now].size(); i++) {
		int curr = v[now][i];
		if (!visited[curr]) {
			cnt++;
			DFS(curr);
		}

	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;

		v[s].push_back(e);
		v[e].push_back(s);
	}

	DFS(1);

	cout << cnt;
}