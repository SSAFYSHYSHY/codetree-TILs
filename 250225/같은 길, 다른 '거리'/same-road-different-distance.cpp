#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>
#include <climits>

using namespace std;

int n, m;
vector<pair<int, int>> a2[100001];
vector<pair<int, int>> b2[100001];

vector<pair<int, int>> a1[100001];
vector<pair<int, int>> b1[100001];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int dist[100001];
int a_dist[100001];
int b_dist[100001];

void Input() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y, c, c2;
		cin >> x >> y >> c >> c2;

		a1[x].push_back({ y,c });
		b1[x].push_back({ y,c2 });

		a2[y].push_back({ x,c });
		b2[y].push_back({ x,c2 });
	}
}

void Dijk(int k, int dist[], vector<pair<int, int>> graph[]) {
	for (int i = 1; i <= n; i++) {
		dist[i] = INT_MAX;
	}
	dist[k] = 0;

	pq.push({ 0,k });

	while (!pq.empty()) {
		int min_dist, min_idx;
		tie(min_dist, min_idx) = pq.top();
		pq.pop();

		for (int i = 0; i < graph[min_idx].size(); i++) {
			int tar_idx, tar_dist;
			tie(tar_idx, tar_dist) = graph[min_idx][i];

			int new_dist = dist[min_idx] + tar_dist;

			if (dist[tar_idx] > new_dist) {
				dist[tar_idx] = new_dist;
				pq.push({ new_dist, tar_idx });
			}
		}
	}
}

void Dijk2(int dist[], int a_dist[], int b_dist[], vector<pair<int,int>> a_graph[], vector<pair<int, int>> b_graph[]) {
	for (int i = 1; i <= n; i++) {
		dist[i] = INT_MAX;
	}
	dist[1] = 0;

	pq.push({ 0,1 });

	while (!pq.empty()) {
		int min_dist, min_idx;
		tie(min_dist, min_idx) = pq.top();
		pq.pop();

		for (int i = 0; i < a_graph[min_idx].size(); i++) {
			int tar_idx;
			int a_cost, b_cost;

			tie(tar_idx, a_cost) = a_graph[min_idx][i];
			tie(tar_idx, b_cost) = b_graph[min_idx][i];

			int tar_dist = 0;
			if (a_dist[tar_idx] + a_cost != a_dist[min_idx]) {
				tar_dist++;
			}
			if (b_dist[tar_idx] + b_cost != b_dist[min_idx]) {
				tar_dist++;
			}

			int new_dist = dist[min_idx] + tar_dist;

			if (dist[tar_idx] > new_dist) {
				dist[tar_idx] = new_dist;
				pq.push({ new_dist, tar_idx });
			}
		}
	}
}

int main() {
	Input();

	Dijk(n, a_dist, a2);
	Dijk(n, b_dist, b2);

	Dijk2(dist, a_dist, b_dist, a1, b1);

	int ans = dist[n];

	cout << ans;
}