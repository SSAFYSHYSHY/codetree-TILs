#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int n, m;
int a[100][100];  // 수치 맵
bool visited[100][100];
int dirs[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };  // 상, 우, 하, 좌 방향

// 범위 벗어나는지 체크
bool out_range(int y, int x) {
    return y < 0 || y >= n || x < 0 || x >= m;
}

// BFS 함수
bool canReach(int k) {
    queue<pair<int, int>> q;
    q.push({ 0, 0 });  // 시작점 (0, 0)
    visited[0][0] = true;

    // BFS 탐색
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        // 목적지에 도달했으면 true 반환
        if (y == n - 1 && x == m - 1) {
            return true;
        }

        // 4방향 탐색
        for (int i = 0; i < 4; ++i) {
            int ny = y + dirs[i][0];
            int nx = x + dirs[i][1];

            // 범위 벗어나면 skip
            if (out_range(ny, nx) || visited[ny][nx]) continue;

            // 경로를 이동하는 조건 체크
            int mi = min(a[y][x], a[ny][nx]);
            int ma = max(a[y][x], a[ny][nx]);

            // 조건을 만족하는지 확인 (k를 기준으로)
            if (ma - mi > k) continue;

            visited[ny][nx] = true;
            q.push({ ny, nx });
        }
    }

    return false;
}

int main() {
    cin >> n >> m;

    // 맵 입력
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    // 이분 탐색을 통해 최적화된 k 값 찾기
    int l = 0, r = 500, ans = INT_MAX;

    while (l <= r) {
        int mid = (l + r) / 2;

        // 방문 배열 초기화
        fill(&visited[0][0], &visited[0][0] + sizeof(visited) / sizeof(bool), false);

        if (canReach(mid)) {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << ans + 1<< endl;
    return 0;
}
