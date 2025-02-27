#include <iostream>

using namespace std;

int n, m, x, y, k;
int arr[21][21];
int dice[6] = {0, 0, 0, 0, 0, 0};

// 이동 방향 (동, 서, 북, 남)
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

// 주사위 회전 함수
void roll(int dir) {
    int temp = dice[0];
    if (dir == 1) { // 동쪽
        dice[0] = dice[5];
        dice[5] = dice[1];
        dice[1] = dice[3];
        dice[3] = temp;
    } else if (dir == 2) { // 서쪽
        dice[0] = dice[3];
        dice[3] = dice[1];
        dice[1] = dice[5];
        dice[5] = temp;
    } else if (dir == 3) { // 북쪽
        dice[0] = dice[4];
        dice[4] = dice[1];
        dice[1] = dice[2];
        dice[2] = temp;
    } else if (dir == 4) { // 남쪽
        dice[0] = dice[2];
        dice[2] = dice[1];
        dice[1] = dice[4];
        dice[4] = temp;
    }
}

// 주사위 이동 및 값 복사
bool moveDice(int dir) {
    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if (nx < 0 || ny < 0 || nx >= n || ny >= m) return false;

    x = nx;
    y = ny;
    roll(dir);

    if (arr[x][y] != 0) {
        dice[0] = arr[x][y];
        arr[x][y] = 0;
    } else {
        arr[x][y] = dice[0];
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    while (k--) {
        int dir;
        cin >> dir;

        if (moveDice(dir)) {
            cout << dice[1] << "\n"; // 윗면 출력
        }
    }

    return 0;
}
