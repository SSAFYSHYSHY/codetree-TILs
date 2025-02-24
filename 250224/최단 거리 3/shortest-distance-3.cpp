#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n, m, a , b;
vector<pair<int, int>> v[1001];
int dist[1001];
priority_queue<pair<int, int>> pq;

void Input() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;

		v[x].push_back({ y,z });
		v[y].push_back({ x,z });
	}
	cin >> a >> b;

	for (int i = 1; i <= n; i++) {
		dist[i] = INT_MAX;
	}
	dist[a] = 0;
}

int main() {
	Input();

	pq.push({ -0, a });

	while (!pq.empty()) {
		int min_dist, min_idx;
		tie(min_dist, min_idx) = pq.top();
		pq.pop();

		for (int i = 0; i < v[min_idx].size(); i++) {
			int tar_idx, tar_dist;
			tie(tar_idx, tar_dist) = v[min_idx][i];

			int new_dist = dist[min_idx] + tar_dist;

			if (dist[tar_idx] > new_dist) {
				dist[tar_idx] = new_dist;
				pq.push({ -new_dist, tar_idx });
			}
		}
	}

	cout << dist[b];
}