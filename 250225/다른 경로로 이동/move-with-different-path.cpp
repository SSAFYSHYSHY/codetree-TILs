#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();
int N, M;
vector<vector<pair<int, int>>> adj;  // 인접 리스트 (노드, 가중치)
vector<vector<bool>> used;           // A가 사용한 간선 표시

// 다익스트라 알고리즘
vector<int> dijkstra(int start, vector<int>& parent) {
    vector<int> dist(N + 1, INF);
    priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        auto [cost, cur] = pq.top(); pq.pop();
        
        if (dist[cur] < cost) continue;  // 이미 더 짧은 경로가 존재하면 무시
        
        for (auto [next, weight] : adj[cur]) {
            if (dist[next] > cost + weight) { 
                dist[next] = cost + weight;
                pq.push({dist[next], next});
                parent[next] = cur;  // 경로 기록
            }
        }
    }
    
    return dist;
}

// A의 최단 경로를 따라 사용된 간선을 제거
void remove_used_edges(int start, int end, vector<int>& parent) {
    int node = end;
    while (node != start) {
        int prev = parent[node];
        for (auto& [next, weight] : adj[prev]) {
            if (next == node) {
                used[prev][next] = true; // 사용된 간선 표시
                break;
            }
        }
        node = prev;
    }
}

int main() {
    cin >> N >> M;
    adj.resize(N + 1);
    used.assign(N + 1, vector<bool>(N + 1, false));

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  // 양방향 그래프
    }

    vector<int> parentA(N + 1, -1);
    vector<int> distA = dijkstra(1, parentA); // A의 최단 경로 계산

    remove_used_edges(1, N, parentA); // A가 사용한 간선 제거

    // B를 위한 새로운 다익스트라 실행 (A가 사용한 간선 제외)
    vector<int> parentB(N + 1, -1);
    vector<int> distB(N + 1, INF);
    priority_queue<tuple<int, int>, vector<tuple<int, int>>, greater<>> pq;

    distB[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [cost, cur] = pq.top(); pq.pop();
        if (distB[cur] < cost) continue;

        for (auto [next, weight] : adj[cur]) {
            if (used[cur][next]) continue;  // A가 사용한 간선은 패스
            if (distB[next] > cost + weight) {
                distB[next] = cost + weight;
                pq.push({distB[next], next});
                parentB[next] = cur;
            }
        }
    }

    cout << (distB[N] == INF ? -1 : distB[N]) << '\n'; // B가 도달 가능하면 거리 출력, 불가능하면 -1

    return 0;
}
