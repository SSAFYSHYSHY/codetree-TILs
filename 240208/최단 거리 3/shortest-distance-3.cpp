#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

using namespace std;

vector<pair<int, int>> v[1001];
priority_queue<pair<int, int>> pq;
int dist[1001];
int s, e;
int n, m;

void Initial() {
	for (int i = 1; i <= n; i++) {
		dist[i] = 1e9;
	}
	dist[s] = 0;

	pq.push(make_pair(-0, s));
}

void Dijk() {
	while (!pq.empty()) {
		int min_idx, min_dist;
		tie(min_dist, min_idx) = pq.top();
		pq.pop();

		min_dist = -min_dist;

		if (min_dist != dist[min_idx]) {
			continue;
		}

		for (int i = 0; i < v[min_idx].size(); i++) {
			int tar_idx, tar_dist;
			tie(tar_idx, tar_dist) = v[min_idx][i];

			int new_dist = dist[min_idx] + tar_dist;

			if (dist[tar_idx] > new_dist) {
				dist[tar_idx] = new_dist;
				pq.push(make_pair(-new_dist, tar_idx));
			}
		}
	}
}

void Print() {
	cout << dist[e];
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;

		v[x].push_back(make_pair(y, w));
		v[y].push_back(make_pair(x, w));
	}
	cin >> s >> e;

	Initial();

	Dijk();

	Print();
}