#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <tuple>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<int, int>> graph[1001];  // 인접 리스트 (u -> {v, weight})
vector<tuple<int, int, int>> edges; // 모든 간선 저장 (u, v, w)

// 다익스트라 알고리즘을 사용하여 최단 거리 계산
int dijkstra(int start, int end) {
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
    
    return dist[end];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
        edges.push_back({u, v, w});
    }

    // 원래의 최단 거리 계산
    int original_shortest = dijkstra(1, n);
    int count = 0;

    // 각 간선을 하나씩 제거하고 최단 거리 비교
    for (auto &[u, v, w] : edges) {
        // 간선 제거
        graph[u].erase(remove_if(graph[u].begin(), graph[u].end(), 
                     [&](pair<int, int> p) { return p.first == v && p.second == w; }), graph[u].end());
        graph[v].erase(remove_if(graph[v].begin(), graph[v].end(), 
                     [&](pair<int, int> p) { return p.first == u && p.second == w; }), graph[v].end());

        // 최단 거리 다시 계산
        int new_shortest = dijkstra(1, n);
        
        // 원래 최단 거리와 다르면 경우의 수 증가
        if (new_shortest != original_shortest) {
            count++;
        }

        // 간선 복구
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    cout << count << "\n";

    return 0;
}
