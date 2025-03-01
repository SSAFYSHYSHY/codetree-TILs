#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int n, m;
int dx[4] = {0, 0, 1, -1}; // 상하좌우 이동
int dy[4] = {1, -1, 0, 0};

// 현재 격자를 비트마스크 정수로 변환
int gridToBitmask(int grid[101][101], int n, int m) {
    int bitmask = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                bitmask |= (1 << (i * m + j));  // 비트 위치에 1을 설정
            }
        }
    }
    return bitmask;
}

// 주어진 위치 (x, y)에 대해 상하좌우 및 자기 자신을 반전하는 비트마스크 연산
int flip(int state, int x, int y, int n, int m) {
    int pos = x * m + y;
    state ^= (1 << pos);  // 자기 자신 반전

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
            int newPos = nx * m + ny;
            state ^= (1 << newPos);  // 상하좌우 반전
        }
    }
    return state;
}

// BFS를 사용한 최소 횟수 탐색
int bfs(int start, int n, int m) {
    queue<pair<int, int>> q;
    unordered_set<int> visited;

    q.push({start, 0});
    visited.insert(start);

    int target = (1 << (n * m)) - 1;  // 모든 비트가 1인 상태

    while (!q.empty()) {
        int state = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (state == target) return steps;  // 모든 칸이 1이면 정답 반환

        // 모든 칸을 하나씩 눌러본다
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int newState = flip(state, i, j, n, m);
                if (visited.find(newState) == visited.end()) {
                    visited.insert(newState);
                    q.push({newState, steps + 1});
                }
            }
        }
    }

    return -1;  // 모든 칸을 1로 만들 수 없는 경우 (문제에서 이런 경우는 없다고 가정)
}

int main() {
    cin >> n >> m;
    int grid[101][101];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int startState = gridToBitmask(grid, n, m);
    cout << bfs(startState, n, m) << endl;

    return 0;
}
