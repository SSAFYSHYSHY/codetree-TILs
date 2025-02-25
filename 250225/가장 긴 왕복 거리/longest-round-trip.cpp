#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int n, m, x;
vector<pair<int, int>> graph[1001];  // 인접 리스트

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

    cin >> n >> m >> x;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    int max_time = 0;

    // X에서 모든 정점까지 최단 거리
    vector<int> dist_from_X = dijkstra(x);

    // 각 정점에서 X까지 왕복 시간 계산
    for (int i = 1; i <= n; i++) {
        if (i == x) continue; // 자기 자신은 제외
        vector<int> dist_to_X = dijkstra(i);
        max_time = max(max_time, dist_to_X[x] + dist_from_X[i]);
    }

    cout << max_time << "\n";
    return 0;
}
