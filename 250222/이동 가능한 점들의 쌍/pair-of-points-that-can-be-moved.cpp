#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, p, q;
    cin >> n >> m >> p >> q;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, INF));

    // 거리 행렬 초기화
    for (int i = 1; i <= n; i++) {
        graph[i][i] = 0;
    }

    // 간선 정보 입력
    for (int i = 0; i < m; i++) {
        int s, e, v;
        cin >> s >> e >> v;
        graph[s][e] = v;
    }

    // Floyd-Warshall 알고리즘 수행
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (graph[i][k] < INF && graph[k][j] < INF) { // 오버플로우 방지
                    graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }
    }

    long long isGo = 0;
    long long answer = 0;

    // 질의 처리
    for (int testCase = 0; testCase < q; testCase++) {
        int start, end;
        cin >> start >> end;

        int dist = INF;
        for (int i = 1; i <= p; i++) {
            if (graph[start][i] < INF && graph[i][end] < INF) { // 빨간점을 경유할 수 있는 경우
                dist = min(dist, graph[start][i] + graph[i][end]);
            }
        }

        if (dist >= INF) continue; // 유효한 경로가 없으면 건너뜀

        answer += dist;
        isGo++;
    }

    cout << isGo << '\n' << answer << '\n';

    return 0;
}
