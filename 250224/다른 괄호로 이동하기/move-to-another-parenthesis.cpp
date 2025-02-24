#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;

#define MAX 50
#define INF INT_MAX

// 상, 하, 좌, 우
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, a, b;  // 미로 크기 N과 기호 비교에 대한 시간 A, B
char maze[MAX][MAX];  // 미로 배열
int dist[MAX][MAX];  // 출발점에서 각 칸까지의 최단 거리

// 다익스트라 알고리즘
int dijkstra(int startX, int startY) {
    // dist 배열 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = INF;  // 최단 거리를 무한대로 설정
        }
    }
    dist[startX][startY] = 0;

    // 우선순위 큐 (가장 짧은 거리가 우선적으로 처리됨)
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({ 0, {startX, startY} });  // 출발점에서의 거리는 0

    while (!pq.empty()) {
        int currentDist = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        // 상하좌우로 인접한 칸을 확인
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 유효한 칸인지 확인 (범위 체크)
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                // 현재 칸과 이동하려는 칸의 기호가 같으면 A시간, 다르면 B시간
                int time = (maze[x][y] == maze[nx][ny]) ? a : b;

                if (currentDist + time < dist[nx][ny]) {
                    dist[nx][ny] = currentDist + time;
                    pq.push({ dist[nx][ny], {nx, ny} });
                }
            }
        }
    }

    // 도착점까지의 최단 거리를 반환
    return dist[n - 1][n - 1];
}

int main() {
    cin >> n >> a >> b;  // 미로 크기 N과 기호 비교 시간 A, B
    // 미로 배열 입력
    for (int i = 0; i < n; i++) {
        cin >> maze[i];
    }

    // 출발점에서 목표점까지의 최단 시간 계산
    int max_time = 0;

    // 모든 칸에 대해 다익스트라를 실행하여 최단 경로를 계산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // i, j에서 출발하여 최단 경로를 계산
            int result = dijkstra(i, j);
            max_time = max(max_time, result);  // 최댓값을 구합니다.
        }
    }

    cout << max_time << endl;  // 최댓값 출력
    return 0;
}
