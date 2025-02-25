#include <iostream>
#include <vector>

using namespace std;

int n, m;
int dist[101][101]; // 크기 비교 관계 저장 (초기값 0)

void floyd_warshall() {
    for (int k = 1; k <= n; k++) { // 경유점
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] == 1 && dist[k][j] == 1) {
                    dist[i][j] = 1; // i > k > j 이므로 i > j
                }
                if (dist[i][k] == -1 && dist[k][j] == -1) {
                    dist[i][j] = -1; // i < k < j 이므로 i < j
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;  // a > b
        dist[b][a] = -1; // b < a
    }

    floyd_warshall();

    // 결과 계산: 비교할 수 없는 정수 개수 출력
    for (int i = 1; i <= n; i++) {
        int known_relations = 0;
        for (int j = 1; j <= n; j++) {
            if (i != j && dist[i][j] != 0) known_relations++;
        }
        cout << (n - 1 - known_relations) << "\n";
    }

    return 0;
}
