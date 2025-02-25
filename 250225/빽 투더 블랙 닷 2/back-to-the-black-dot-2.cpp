#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n, m, r1, r2;
vector<pair<int, int>> graph[1001];  // 인접 리스트 (u -> {v, weight})

// 다익스트라: 특정 시작점에서 모든 노드까지 최단 거리 계산
vector<int> dijkstra(int start) {
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int now_dist = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if (now_dist > dist[now]) continue;

        for (auto &[next, weight] : graph[now]) {
            int new_dist = now_dist + weight;
            if (new_dist < dist[next]) {
                dist[next] = new_dist;
                pq.push({new_dist, next});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    cin >> r1 >> r2;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    // 모든 노드에서의 최단 거리 계산
    vector<int> dist_from_r1 = dijkstra(r1);
    vector<int> dist_from_r2 = dijkstra(r2);

    int min_distance = INT_MAX;

    // 가능한 검은색 점을 시작점으로 설정
    for (int i = 1; i <= n; i++) {
        if (i == r1 || i == r2) continue; // 빨간 점은 시작점이 될 수 없음

        // i -> r1 -> r2 -> i 와 i -> r2 -> r1 -> i 중 최소값
        int route1 = dist_from_r1[i] + dist_from_r1[r2] + dist_from_r2[i];
        int route2 = dist_from_r2[i] + dist_from_r2[r1] + dist_from_r1[i];
        min_distance = min(min_distance, min(route1, route2));
    }

    cout << min_distance << "\n";
    return 0;
}
