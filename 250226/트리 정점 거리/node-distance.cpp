#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_N 1000

using namespace std;

int n, m;
vector<pair<int, int>> v[1001];
bool visited[1001];
int dist[1001];

void Input() {
	cin >> n >> m;

	for (int i = 0; i < n - 1; i++) {
		int x, y, w;
		cin >> x >> y >> w;

		v[x].push_back({ y,w });
		v[y].push_back({ x,w });
	}
}

void DFS(int start, int endi) {
	//만약 원하는 정점에 도달하면.
	if (start == endi) {
		return;
	}

	//그렇지 않으면 계속 DFS 색출.
	for (int i = 0; i < v[start].size(); i++) {
		int y = v[start][i].first;
		int cost = v[start][i].second;

		if (!visited[y]) {
			visited[y] = true;
			dist[y] = dist[start] + cost;
			DFS(y, endi);
		}
	}
}

int Calc(int start, int endi) {
	//visited 초기화 및 start 위치에 대해 true 연산.
	for (int i = 0; i < MAX_N; i++) {
		visited[i] = false;
		dist[i] = 0;
	}
	visited[start] = true;
	dist[start] = 0;

	DFS(start, endi);

	return dist[endi];
}

int main() {
	Input();

	//m 만큼 반복해서 시뮬 시작.
	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;

		int dist = Calc(s, e);

		cout << dist << "\n";
	}
}