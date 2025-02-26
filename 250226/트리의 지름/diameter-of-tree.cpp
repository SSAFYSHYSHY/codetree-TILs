#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[100001];
vector<pair<int, int>> v[100001];
int n, ans = 0;
int dist[100001];

void Input() {
	cin >> n;

	for (int i = 1; i <= n - 1; i++) {
		int x, y, w;
		cin >> x >> y >> w;

		v[x].push_back({ y,w });
		v[y].push_back({ x,w });
	}
}

void DFS(int num, int sum) {

	for (int i = 0; i < v[num].size(); i++) {
		int y = v[num][i].first;
		int cost = v[num][i].second;

		if (!visited[y]) {
			visited[y] = true;
			dist[y] = sum + cost;

			DFS(y, sum + cost);
		}

	}
}

pair<int, int> Calc(int x) {
	for (int i = 1; i <= n; i++) {
		visited[i] = false;
		dist[i] = 0;
	}

	visited[x] = true;
	dist[x] = 0;
	DFS(x, 0);

	int idx = -1;
	int path = -1;

	for (int i = 1; i <= n; i++) {
		if (dist[i] > path) {
			path = dist[i];
			idx = i;
		}
	}

	return make_pair(idx, path);
}


int main() {
	Input();

	int idx;
	tie(idx, ignore) = Calc(1);

	int dist;
	tie(ignore, dist) = Calc(idx);

	cout << dist;
}
