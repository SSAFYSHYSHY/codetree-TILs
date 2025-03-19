#include <iostream>
using namespace std;

int n, ans = 0;
int arr[501][501];

int dx[] = { 0, 1, 0, -1 }; // ← ↓ → ↑
int dy[] = { -1, 0, 1, 0 };

int dice[4][5][5] = {
    {{0,0,2,0,0},{0,10,7,1,0},{5,0,0,0,0},{0,10,7,1,0},{0,0,2,0,0}},
    {{0,0,0,0,0},{0,1,0,1,0},{2,7,0,7,2},{0,10,0,10,0},{0,0,5,0,0}},
    {{0,0,2,0,0},{0,1,7,10,0},{0,0,0,0,5},{0,1,7,10,0},{0,0,2,0,0}},
    {{0,0,5,0,0},{0,10,0,10,0},{2,7,0,7,2},{0,1,0,1,0},{0,0,0,0,0}}
};

void Input() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
}

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

void Add(int x, int y, int num) {
    if (!InRange(x, y)) ans += num;
    else arr[x][y] += num;
}

void Move(int x, int y, int dir) {
    int added_dust = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int dust = arr[x][y] * dice[dir][i][j] / 100;
            Add(x + i - 2, y + j - 2, dust);
            added_dust += dust;
        }
    }
    // 알파(남은 모래)는 정방향 한 칸 앞에
    Add(x + dx[dir], y + dy[dir], arr[x][y] - added_dust);
}

int main() {
    Input();

    int dir = 0, cnt = 0, dist = 1, dist_cnt = 0;
    int x = n / 2, y = n / 2;

    while (cnt < n * n - 1) {
        for (int i = 0; i < dist; i++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (!InRange(nx, ny)) break;

            Move(nx, ny, dir);
            arr[nx][ny] = 0;

            x = nx;
            y = ny;
            cnt++;
        }

        dir = (dir + 1) % 4;
        dist_cnt++;
        if (dist_cnt == 2) {
            dist++;
            dist_cnt = 0;
        }
    }

    cout << ans << "\n";
    return 0;
}
