#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n, m, x = 0, y = 0, ans = 0;
int dir = 0;

// 동(0), 남(1), 서(2), 북(3)
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

// 주사위 (아래, 위, 북, 동, 남, 서)
int dice[] = { 6, 1, 5, 3, 2, 4 };

// 주사위 회전 (동, 남, 서, 북)
int dice_roll[4][6] = {
    {3, 5, 2, 1, 4, 0},
    {4, 2, 0, 3, 1, 5},
    {5, 3, 2, 0, 4, 1},
    {2, 4, 1, 3, 0, 5}
};

int arr[21][21];
bool visited[21][21];

// 범위 체크
bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

// BFS로 같은 숫자 그룹 크기 구하기
int BFS(int sx, int sy, int num) {
    memset(visited, false, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({ sx, sy });
    visited[sx][sy] = true;

    int sum = num, count = 1;

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == num) {
                q.push({ nx, ny });
                visited[nx][ny] = true;
                count++;
            }
        }
    }

    return sum * count;
}

// 입력 처리
void Input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
}

int main() {
    Input();

    while (m--) {
        // 주사위 이동
        int nx = x + dx[dir], ny = y + dy[dir];

        // 범위를 벗어나면 방향 반대로 변경
        if (!InRange(nx, ny)) {
            dir = (dir + 2) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }

        x = nx;
        y = ny;

        // 주사위 굴리기
        int new_dice[6];
        for (int i = 0; i < 6; i++)
            new_dice[i] = dice[dice_roll[dir][i]];
        for (int i = 0; i < 6; i++)
            dice[i] = new_dice[i];

        // 점수 계산 (BFS 실행)
        ans += BFS(x, y, arr[x][y]);

        // 방향 결정 (주사위 아랫면과 격자 숫자 비교)
        if (dice[0] > arr[x][y]) { // 주사위 아랫면이 크면 시계 방향 회전
            dir = (dir + 1) % 4;
        }
        else if (dice[0] < arr[x][y]) { // 주사위 아랫면이 작으면 반시계 방향 회전
            dir = (dir - 1 + 4) % 4;
        }
    }

    cout << ans;
}
