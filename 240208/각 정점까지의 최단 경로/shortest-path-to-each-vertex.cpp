#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <tuple>
#include <climits>

using namespace std;

vector<pair<int, int>> v[20001];
priority_queue<pair<int, int>> pq;
int dist[300001];
int n, m, k;

void Dijk() {
	while (!pq.empty()) {
		//가장 가까운 거리를 받고, 원소 제거.
		int min_dist, min_idx;
		tie(min_dist, min_idx) = pq.top();
		pq.pop();

		//가장 가까운 거리에 - 을 다시 붙임. 우선순위 큐가 큰 값을 우선으로 뽑아버리기 때문 기초 값이 -.
		min_dist = -min_dist;

		//우선순위 큐 이용시 같은 정점의 원소가 여러번 들어가는 문제가 발생.
		//min_dist가 최신 dist[min_idx]값과 다르다면 계산할 필요 없이 패스.
		if (min_dist != dist[min_idx])
			continue;

		//최솟값에 해당되는 정점에 연결된 간선들을 보며
		//시작점으로부터 최단 거리 갱신.
		for (int j = 0; j < (int)v[min_idx].size(); j++) {
			int tar_idx, tar_dist;
			tie(tar_idx, tar_dist) = v[min_idx][j];

			//현재 위치에서 연결된 간선으로 가는 것이 더 작으면.
			int new_dist = dist[min_idx] + tar_dist;

			if (dist[tar_idx] > new_dist) {
				dist[tar_idx] = new_dist;
				pq.push(make_pair(-new_dist, tar_idx));
			}
		}

	}
}

int main() {
	cin >> n >> m >> k;

	//입력.
	for (int i = 0; i < m; i++) {
		int x, y, w;
		cin >> x >> y >> w;

		v[x].push_back(make_pair(y, w));
		v[y].push_back(make_pair(x, w));
	}

	//거리 누적합 초기화, queue에 초기 시작 위치와 가중치 삽입.
	for (int i = 1; i <= n; i++) {
		dist[i] = 1e9;
	}
	dist[k] = 0;
	pq.push(make_pair(-0, k));

	//Dijk 함수 시작.

	Dijk();

	//출력.

	for (int i = 1; i <= n; i++) {
		if (dist[i] == 1e9) {
			cout << -1 << "\n";
		}
		else {
			cout << dist[i] << "\n";
		}
	}

}