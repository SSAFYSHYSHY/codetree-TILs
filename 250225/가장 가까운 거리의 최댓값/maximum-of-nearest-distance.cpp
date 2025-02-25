#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>

using namespace std;

const int INF = numeric_limits<int>::max();
vector<vector<pair<int, int>>> graph;

vector<int> dijkstra(int start, int n) {
    vector<int> dist(n + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    dist[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& [v, w] : graph[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({ dist[v], v });
            }
        }
    }

    return dist;
}

int main() {
    int N, M;
    cin >> N >> M;

    int A, B, C;
    cin >> A >> B >> C;

    graph.resize(N + 1);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({ v, w });
        graph[v].push_back({ u, w });
    }

    vector<int> distA = dijkstra(A, N);
    vector<int> distB = dijkstra(B, N);
    vector<int> distC = dijkstra(C, N);

    int result = 0;

    for (int i = 1; i <= N; i++) {
        if (i == A || i == B || i == C) continue;
        int minDist = min({ distA[i], distB[i], distC[i] });
        result = max(result, minDist);
    }

    cout << result << endl;

    return 0;
}
