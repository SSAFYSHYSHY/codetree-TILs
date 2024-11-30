#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m, ans = 0, dir = 0, x = 0, y = 0, sum = 0;
int arr[21][21];
bool visited[21][21];
// 위, 동, 서, 남, 북, 아래
int dice[] = { 1, 3, 4, 2, 5, 6 };

// 동, 남, 서, 북 (시계 방향)
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

int BFS(int cx, int cy) {
    queue<pair<int, int>> q;
    q.push({ cx, cy });
    visited[cx][cy] = true;
    int sum_num = arr[cx][cy];
    int value = arr[cx][cy]; // 기준 값

    while (!q.empty()) {
        int ccx = q.front().first;
        int ccy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = ccx + dx[i];
            int ny = ccy + dy[i];

            if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == value) {
                q.push({ nx, ny });
                visited[nx][ny] = true;
                sum_num += arr[nx][ny];
            }
        }
    }

    return sum_num;
}

void Roll(int dir) {
    int temp[6];
    for (int i = 0; i < 6; i++) temp[i] = dice[i];

    // 동
    if (dir == 0) {
        dice[0] = temp[2];
        dice[1] = temp[0];
        dice[2] = temp[5];
        dice[5] = temp[1];
    }
    // 남
    else if (dir == 1) {
        dice[0] = temp[4];
        dice[4] = temp[5];
        dice[5] = temp[3];
        dice[3] = temp[0];
    }
    // 서
    else if (dir == 2) {
        dice[0] = temp[1];
        dice[1] = temp[5];
        dice[2] = temp[0];
        dice[5] = temp[2];
    }
    // 북
    else if (dir == 3) {
        dice[0] = temp[3];
        dice[3] = temp[5];
        dice[4] = temp[0];
        dice[5] = temp[4];
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    while (m--) {
        // 주사위 굴리기
        Roll(dir);

        // 이동
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (!InRange(nx, ny)) {
            // 경계 밖이면 반대 방향으로 이동
            dir = (dir + 2) % 4;
            nx = x + dx[dir];
            ny = y + dy[dir];
        }

        x = nx;
        y = ny;

        // BFS로 점수 계산
        memset(visited, false, sizeof(visited));
        sum += BFS(x, y);

        // 방향 결정
        int dice_num = dice[5];
        int arr_num = arr[x][y];

        if (dice_num > arr_num) {
            dir = (dir + 1) % 4; // 시계 방향 회전
        }
        else if (dice_num < arr_num) {
            dir = (dir + 3) % 4; // 반시계 방향 회전
        }
    }

    cout << sum << endl;

    return 0;
}