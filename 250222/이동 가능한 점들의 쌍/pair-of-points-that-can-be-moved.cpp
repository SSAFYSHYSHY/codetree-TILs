#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const long long INF = 1e9;  // 무한대 값 설정

long long N, M, P, Q;
vector<long long> redPoint;
vector<vector<long long>> dist;

bool hasRedPoint(long long A, long long B) {
    if (A <= P || B <= P) return true; // 출발점 또는 도착점이 빨간점인 경우

    // 경로 내 빨간점이 포함되는지 확인
    for (long long red : redPoint) {
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
    dist.assign(N + 1, vector<long long>(N + 1, INF));
    for (long long i = 1; i <= N; i++) dist[i][i] = 0;

    // 빨간점 리스트 저장
    for (long long i = 1; i <= P; i++) {
        redPoint.push_back(i);
    }

    // 간선 입력
    for (long long i = 0; i < M; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }

    // Floyd-Warshall 알고리즘 수행
    for (long long k = 1; k <= N; k++) {
        for (long long i = 1; i <= N; i++) {
            for (long long j = 1; j <= N; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    long long validQueries = 0;
    long long totalCost = 0;

    // 질의 처리
    for (long long i = 0; i < Q; i++) {
        long long A, B;
        cin >> A >> B;

        if (dist[A][B] != INF && hasRedPoint(A, B)) {
            validQueries++;
            totalCost += dist[A][B];
        }
    }

    cout << validQueries << '\n' << totalCost << '\n';
    return 0;
}
