#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX_N 20
#define DIR_NUM 4

int n, m;
int grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

// 방향: 오른쪽, 아래, 왼쪽, 위
int dx[DIR_NUM] = { 0, 1, 0, -1 };
int dy[DIR_NUM] = { 1, 0, -1, 0 };

// 주사위 상태 배열
int dice[6] = { 1, 2, 3, 5, 4, 6 };

// 현재 위치와 방향
int x = 0, y = 0, move_dir = 0, ans = 0;

// 격자 범위 확인
bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

// BFS로 점수를 계산
int BFS(int x, int y) {
    memset(visited, false, sizeof(visited));

    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;

    int target = grid[x][y];
    int score = 0;

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();

        score += target;

        for (int i = 0; i < DIR_NUM; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (InRange(nx, ny) && !visited[nx][ny] && grid[nx][ny] == target) {
                visited[nx][ny] = true;
                q.push({ nx, ny });
            }
        }
    }
    return score;
}

// 주사위를 특정 방향으로 굴립니다.
void Roll(int dir) {
    int temp[6];
    for (int i = 0; i < 6; i++) temp[i] = dice[i];

    if (dir == 0) { // 오른쪽
        dice[0] = temp[3];
        dice[1] = temp[1];
        dice[2] = temp[0];
        dice[3] = temp[5];
        dice[4] = temp[4];
        dice[5] = temp[2];
    }
    else if (dir == 1) { // 아래쪽
        dice[0] = temp[4];
        dice[1] = temp[0];
        dice[2] = temp[2];
        dice[3] = temp[3];
        dice[4] = temp[5];
        dice[5] = temp[1];
    }
    else if (dir == 2) { // 왼쪽
        dice[0] = temp[2];
        dice[1] = temp[1];
        dice[2] = temp[5];
        dice[3] = temp[0];
        dice[4] = temp[4];
        dice[5] = temp[3];
    }
    else if (dir == 3) { // 위쪽
        dice[0] = temp[1];
        dice[1] = temp[5];
        dice[2] = temp[2];
        dice[3] = temp[3];
        dice[4] = temp[0];
        dice[5] = temp[4];
    }
}

// 이동과 방향 갱신을 포함한 시뮬레이션
void Simulate() {
    // 이동
    int nx = x + dx[move_dir];
    int ny = y + dy[move_dir];

    // 격자 밖이라면 방향을 반대로
    if (!InRange(nx, ny)) {
        move_dir = (move_dir + 2) % 4;
        nx = x + dx[move_dir];
        ny = y + dy[move_dir];
    }

    // 위치 갱신
    x = nx;
    y = ny;

    // 주사위 굴리기
    Roll(move_dir);

    // 점수 계산
    int score = BFS(x, y);
    ans += score;

    // 점수 반영

    // 주사위 아래쪽 숫자
    int bottom = dice[5];

    // 방향 갱신
    if (bottom > grid[x][y]) {
        move_dir = (move_dir + 1) % 4; // 시계 방향
    }
    else if (bottom < grid[x][y]) {
        move_dir = (move_dir + 3) % 4; // 반시계 방향
    }
}

int main() {
    // 입력
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];

    // 시뮬레이션 진행
    for (int i = 0; i < m; i++) {
        Simulate();
    }

    // 결과 출력
    cout << ans << endl;

    return 0;
}