#include <iostream>
#include <vector>

using namespace std;

vector<int> v[1001];
int n, m, ans = 0;
bool visited[1001];

void DFS(int num) {
	for (int i = 0; i < v[num].size(); i++) {
		int curr = v[num][i];

		if (!visited[curr]) {
			visited[curr] = true;
			ans++;
			DFS(num + 1);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		v[x].push_back(y);
		v[y].push_back(x);
	}

	DFS(1);
	visited[1] = true;
	cout << ans - 1;
}