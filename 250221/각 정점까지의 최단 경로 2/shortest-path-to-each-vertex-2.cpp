#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9 // 충분히 큰 값

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, INF));

    // 자기 자신으로 가는 거리는 0
    for (int i = 1; i <= N; i++) {
        dist[i][i] = 0;
    }

    // 간선 입력
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w); // 중복 간선 고려하여 최소값 사용
    }

    // 플로이드-워셜 알고리즘
    for (int k = 1; k <= N; k++) { // 거쳐가는 노드
        for (int i = 1; i <= N; i++) { // 시작 노드
            for (int j = 1; j <= N; j++) { // 도착 노드
                if (dist[i][k] < INF && dist[k][j] < INF) { // 오버플로우 방지
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // 결과 출력
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (dist[i][j] == INF) cout << "-1 ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
