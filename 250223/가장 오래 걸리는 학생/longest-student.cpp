#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> pii;
const int INF = numeric_limits<int>::max();

vector<int> dijkstra(int n, vector<vector<pii>>& graph, int start) {
    vector<int> distance(n + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    distance[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        if (distance[node] < dist) continue;
        
        for (auto& edge : graph[node]) {
            int next_node = edge.first;
            int cost = edge.second;
            int new_dist = dist + cost;
            if (new_dist < distance[next_node]) {
                distance[next_node] = new_dist;
                pq.push({new_dist, next_node});
            }
        }
    }
    
    return distance;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> graph(n + 1);
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    
    int school = n; // 학교 위치
    vector<int> min_distances = dijkstra(n, graph, school);
    int max_time = 0;
    
    for (int i = 1; i < n; i++) {
        max_time = max(max_time, min_distances[i]);
    }
    
    cout << max_time << '\n';
    return 0;
}
