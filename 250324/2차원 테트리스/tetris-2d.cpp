#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int k, t, ans = 0;
int n = 6, m = 4;

int dice[4][2][2] = {
    {},
    {{1, 0},
     {0, 0}},
    {{1, 1},
     {0, 0}},
    {{1, 0},
     {1, 0}}
};

int board[2][6][4];

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool CanGo(int b_num, int dice_type, int x, int y) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (dice[dice_type][i][j]) {
                int nx = x + i;
                int ny = y + j;

                if (!InRange(nx, ny) || board[b_num][nx][ny]) {
                    return false;
                }
            }
        }
    }
    return true;
}

void Put(int b_num, int dice_type, int x, int y) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (dice[dice_type][i][j]) {
                int nx = x + i;
                int ny = y + j;
                board[b_num][nx][ny] = 1;
            }
        }
    }
}

bool Filled(int b_num, int row) {
    for (int i = 0; i < m; i++) {
        if (board[b_num][row][i] == 0) {
            return false;
        }
    }
    return true;
}

void Drop(int b_num, int end_row) {
    for (int i = end_row; i >= 1; i--) {
        for (int j = 0; j < m; j++) {
            board[b_num][i][j] = board[b_num][i - 1][j];
            board[b_num][i - 1][j] = 0;
        }
    }
}

void Process_Dark(int b_num) {
    int row = n - 1;
    while (row >= 2) {
        if (Filled(b_num, row)) {
            ans++;
            Drop(b_num, row);
        } else {
            row--;
        }
    }
}

bool BlockExist(int b_num, int row) {
    for (int col = 0; col < m; col++) {
        if (board[b_num][row][col] == 1) {
            return true;
        }
    }
    return false;
}

void Process_Light(int b_num) {
    int drop_cnt = 0;
    if (BlockExist(b_num, 0)) {
        drop_cnt++;
    }
    if (BlockExist(b_num, 1)) {
        drop_cnt++;
    }
    while (drop_cnt--) {
        Drop(b_num, n - 1);
    }
}

void Drop_Block(int b_num, int dice_type, int col) {
    for (int row = 0; row < n; row++) {
        if (!CanGo(b_num, dice_type, row + 1, col)) {
            Put(b_num, dice_type, row, col);
            break;
        }
    }

    Process_Dark(b_num);
    Process_Light(b_num);
}

void Calc(int t, int x, int y) {
    // 노란 영역.
    Drop_Block(0, t, y);

    // 빨간 영역.
    if (t == 1) {
        Drop_Block(1, 1, m - 1 - x);
    } else if (t == 2) {
        Drop_Block(1, 3, m - 1 - x);
    } else {
        Drop_Block(1, 2, m - 1 - (x + 1));
    }
}

int Ans(){
    int cnt = 0;
    for(int l = 0; l < 2 ; l++) {
        for(int i = 0; i < n ; i++) {
            for(int j = 0; j < m ; j++) {
                cnt += board[l][i][j];
            }
        }
    }

    return cnt;
}

int main() {
    cin >> k;

    for (int i = 0; i < k; i++) {
        int t, x, y;
        cin >> t >> x >> y;

        Calc(t, x, y);
    }

    cout << ans << endl << Ans();

    return 0;
}
