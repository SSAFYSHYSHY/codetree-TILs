#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

int n, m,s,e;
vector<pair<int, int>> v[1001];
priority_queue<pair<int, int>> pq;
int dist[100001];
int path[100001];

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
			int new_dist;

			new_dist = dist[min_idx] + tar_dist;

			if (dist[tar_idx] > new_dist) {
				dist[tar_idx] = new_dist;
				path[tar_idx] = min_idx;
				pq.push(make_pair(-new_dist, tar_idx));
			}

		}

	}
}

void Print() {
	int x = e;
	vector<int> ve;
	ve.push_back(x);

	while (x != s) {
		x = path[x];
		ve.push_back(x);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dist[i]);
	}

	cout << ans << "\n";

	for (int i = ve.size() - 1; i >= 0; i--) {
		cout << ve[i] << " ";
	}
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