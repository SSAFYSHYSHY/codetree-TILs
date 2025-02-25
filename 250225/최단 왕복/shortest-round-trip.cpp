#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9; // 무한대 값 설정
int n, m;
int dist[101][101]; // 정점 최대 100개

void floyd_warshall() {
    for (int k = 1; k <= n; k++) { // 경유점
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    // 거리 배열 초기화
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0; // 자기 자신으로 가는 비용 0
            else dist[i][j] = INF; // 초기에는 모든 경로를 무한대로 설정
        }
    }

    // 입력 처리
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = c; // 방향 그래프이므로 한 방향만 설정
    }

    // 플로이드-워셜 알고리즘 수행
    floyd_warshall();

    // 최소 왕복 비용 찾기
    int min_cost = INF;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) { // i ≠ j 인 경우만 고려
            if (dist[i][j] != INF && dist[j][i] != INF) { // 왕복 가능해야 함
                min_cost = min(min_cost, dist[i][j] + dist[j][i]);
            }
        }
    }

    // 결과 출력
    if (min_cost == INF) cout << -1 << "\n"; // 왕복 가능한 경우가 없는 경우
    else cout << min_cost << "\n";

    return 0;
}
