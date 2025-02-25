#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

long long n, m, r1, r2;
vector<pair<long long, long long>> graph[100001];  // 인접 리스트 (u -> {v, weight})

// 다익스트라: 특정 시작점에서 모든 노드까지 최단 거리 계산
vector<long long> dijkstra(long long start) {
    vector<long long> dist(n + 1, LLONG_MAX);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        long long now_dist = pq.top().first;
        long long now = pq.top().second;
        pq.pop();

        if (now_dist > dist[now]) continue;

        for (auto &[next, weight] : graph[now]) {
            long long new_dist = now_dist + weight;
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

    for (long long i = 0; i < m; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    // 모든 노드에서의 최단 거리 계산
    vector<long long> dist_from_r1 = dijkstra(r1);
    vector<long long> dist_from_r2 = dijkstra(r2);

    long long min_distance = LLONG_MAX;

    // 가능한 검은색 점을 시작점으로 설정
    for (long long i = 1; i <= n; i++) {
        if (i == r1 || i == r2) continue; // 빨간 점은 시작점이 될 수 없음

        // i -> r1 -> r2 -> i 와 i -> r2 -> r1 -> i 중 최소값
        long long route1 = dist_from_r1[i] + dist_from_r1[r2] + dist_from_r2[i];
        long long route2 = dist_from_r2[i] + dist_from_r2[r1] + dist_from_r1[i];
        min_distance = min(min_distance, min(route1, route2));
    }

    cout << min_distance << "\n";
    return 0;
}
