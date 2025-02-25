#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int u, v, w;
};

int n, m;
vector<Edge> edges;
vector<pair<int, int>> graph[1001];

// 다익스트라: 정점 1에서 모든 정점까지 최단 거리 계산
vector<int> dijkstra() {
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[1] = 0;
    pq.push({0, 1});

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

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    // 원래 최단 거리 계산
    vector<int> original_dist = dijkstra();
    int original_shortest = original_dist[n];

    int max_increase = 0;

    // 모든 간선을 하나씩 2배로 증가 후 테스트
    for (auto &[u, v, w] : edges) {
        // 간선 가중치 증가
        for (auto &edge : graph[u]) {
            if (edge.first == v) edge.second *= 2;
        }
        for (auto &edge : graph[v]) {
            if (edge.first == u) edge.second *= 2;
        }

        // 변경된 상태에서 다시 다익스트라 실행
        vector<int> new_dist = dijkstra();
        int new_shortest = new_dist[n];

        // 최단 거리 증가량 업데이트
        max_increase = max(max_increase, new_shortest - original_shortest);

        // 간선 가중치 원래대로 되돌리기
        for (auto &edge : graph[u]) {
            if (edge.first == v) edge.second /= 2;
        }
        for (auto &edge : graph[v]) {
            if (edge.first == u) edge.second /= 2;
        }
    }

    cout << max_increase << "\n";
    return 0;
}
