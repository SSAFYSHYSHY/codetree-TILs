#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1e9;  // 무한대 값 설정

int N, M, P, Q;
vector<int> redPoints;
vector<vector<int>> dist;

bool hasRedPoint(int A, int B) {
    if (A <= P || B <= P) return true; // 출발점 또는 도착점이 빨간점인 경우

    // 경로 내 빨간점이 포함되는지 확인
    for (int red : redPoints) {
        if (dist[A][red] != INF && dist[red][B] != INF) {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> P >> Q;
    
    // 거리 행렬 초기화
    dist.assign(N + 1, vector<int>(N + 1, INF));
    for (int i = 1; i <= N; i++) dist[i][i] = 0;

    // 빨간점 리스트 저장
    for (int i = 1; i <= P; i++) {
        redPoints.push_back(i);
    }

    // 간선 입력
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }

    // Floyd-Warshall 알고리즘 수행
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    int validQueries = 0;
    int totalCost = 0;

    // 질의 처리
    for (int i = 0; i < Q; i++) {
        int A, B;
        cin >> A >> B;

        if (dist[A][B] != INF && hasRedPoint(A, B)) {
            validQueries++;
            totalCost += dist[A][B];
        }
    }

    cout << validQueries << '\n' << totalCost << '\n';
    return 0;
}
