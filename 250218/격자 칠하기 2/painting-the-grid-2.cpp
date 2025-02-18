#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int grid[101][101];  // 최대 100x100
bool visited[101][101];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// ✅ BFS 한 번만 실행해서 색칠 가능한 영역 확인
bool Check(int D) {
    memset(visited, false, sizeof(visited));
    int half = (n * n + 1) / 2;  // 과반수 조건 (반올림)

    int max_painted = 0;

    // 모든 칸을 시작점으로 한 번만 BFS 수행
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j]) continue; // 이미 탐색한 곳은 스킵

            queue<pair<int, int>> q;
            vector<pair<int, int>> region;
            q.push({i, j});
            visited[i][j] = true;
            region.push_back({i, j});

            while (!q.empty()) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d];
                    int ny = y + dy[d];

                    if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                        if (abs(grid[nx][ny] - grid[x][y]) <= D) {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                            region.push_back({nx, ny});
                        }
                    }
                }
            }
            
            // 최대 색칠 가능 칸 갱신
            max_painted = max(max_painted, (int)region.size());

            // 만약 색칠된 칸이 과반수 이상이면 True 반환
            if (max_painted >= half) return true;
        }
    }
    return false;
}

int main() {
    cin >> n;
    int minValue = 1e9, maxValue = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            minValue = min(minValue, grid[i][j]);
            maxValue = max(maxValue, grid[i][j]);
        }
    }

    // ✅ 이진 탐색으로 최소 D 값 찾기
    int left = 0, right = maxValue - minValue, answer = right;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (Check(mid)) {
            answer = mid;  // 가능한 최소 D 갱신
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << answer;
}
