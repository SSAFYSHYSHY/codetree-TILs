#include <iostream>

#define MAX_N 100
#define MAX_M 10

using namespace std;

const int dx[5] = { 0, -1, 0, 1, 0 }, dy[5] = { 0, 0, -1, 0, 1 };

int n, m;
int board[MAX_N + 1][MAX_M + 1];
int board_original[MAX_N + 1][MAX_M + 1];

bool isOutrange(int x, int y) {
    return !(1 <= x and x <= n and 1 <= y and y <= m);
}

int ans = 1e9;

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> board[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            board_original[i][j] = board[i][j];

    for (int state = 0; state < (1 << m); state++) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                board[i][j] = board_original[i][j];

        for (int y = 1; y <= m; y++) {
            if ((state >> (y - 1)) & 1) {
                int x = 1;
                for (int dir = 0; dir < 5; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if (isOutrange(nx, ny)) continue;

                    board[nx][ny] = 1 - board[nx][ny];
                }
            }
        }

        int num = 0;
        for (int y = 1; y <= m; y++) {
            if ((state >> (y - 1)) & 1)
                num++;
        }

        int cnt = 0;
        for (int i = 2; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                if (board[i - 1][j] == 0) {
                    num++;
                    for (int dir = 0; dir < 5; dir++) {
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];

                        if (isOutrange(nx, ny))
                            continue;

                        board[nx][ny] = 1 - board[nx][ny];
                    }
                }
            }

        bool full_filled = true;
        for (int j = 1; j <= m; j++)
            if (!board[n][j]) full_filled = false;

        if (full_filled)
            ans = min(ans, num);
    }

    if (ans == 1e9)
        cout << -1;
    else
        cout << ans;

    return 0;
}
