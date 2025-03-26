#include <iostream>
#include <tuple>
#include <algorithm>

#define DIR_NUM 8
#define MAX_N 4
#define TAGGER make_pair(-2, -2)
#define BLANK make_pair(-1, -1)

using namespace std;

int n = 4;

pair<int, int> board[MAX_N][MAX_N];

int dx[DIR_NUM] = { -1, -1,  0,  1, 1, 1, 0, -1 };
int dy[DIR_NUM] = { 0, -1, -1, -1, 0, 1, 1,  1 };

int max_score;

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool ThiefCanGo(int x, int y) {
    return InRange(x, y) && board[x][y] != TAGGER;
}

bool TaggerCanGo(int x, int y) {
    return InRange(x, y) && board[x][y] != BLANK;
}

bool Done(int x, int y, int d) {
    for (int dist = 1; dist <= n; dist++) {
        int nx = x + dx[d] * dist, ny = y + dy[d] * dist;
        if (TaggerCanGo(nx, ny))
            return false;
    }

    return true;
}

tuple<int, int, int> GetNext(int x, int y, int move_dir) {
    for (int rotate_num = 0; rotate_num < 8; rotate_num++) {
        int adjusted_dir = (move_dir + rotate_num) % 8;
        int next_x = x + dx[adjusted_dir];
        int next_y = y + dy[adjusted_dir];
        if (ThiefCanGo(next_x, next_y))
            return make_tuple(next_x, next_y, adjusted_dir);
    }
    return make_tuple(x, y, move_dir);
}

void Swap(int x, int y, int next_x, int next_y) {
    pair<int, int> temp_piece = board[x][y];
    board[x][y] = board[next_x][next_y];
    board[next_x][next_y] = temp_piece;
}

void Move(int target_num) {
    for (int x = 0; x < n; x++)
        for (int y = 0; y < n; y++) {
            int piece_num, move_dir;
            tie(piece_num, move_dir) = board[x][y];
            if (piece_num == target_num) {
                int next_x, next_y, next_dir;
                tie(next_x, next_y, next_dir) = GetNext(x, y, move_dir);
                board[x][y] = make_pair(piece_num, next_dir);
                Swap(x, y, next_x, next_y);
                return;
            }
        }
}

void MoveAll() {
    for (int i = 1; i <= n * n; i++)
        Move(i);
}

void SearchMaxScore(int x, int y, int d, int score) {
    if (Done(x, y, d)) {
        max_score = max(max_score, score);
        return;
    }

    for (int dist = 1; dist <= n; dist++) {
        int nx = x + dx[d] * dist, ny = y + dy[d] * dist;
        if (!TaggerCanGo(nx, ny))
            continue;

        pair<int, int> temp[MAX_N][MAX_N];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                temp[i][j] = board[i][j];

        int extra_score, next_dir;
        tie(extra_score, next_dir) = board[nx][ny];
        board[nx][ny] = TAGGER;
        board[x][y] = BLANK;

        MoveAll();

        SearchMaxScore(nx, ny, next_dir, score + extra_score);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board[i][j] = temp[i][j];
    }
}

int main() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int p, d;
            cin >> p >> d;
            board[i][j] = make_pair(p, d - 1);
        }

    int init_score, init_dir;
    tie(init_score, init_dir) = board[0][0];
    board[0][0] = TAGGER;

    MoveAll();

    SearchMaxScore(0, 0, init_dir, init_score);
    cout << max_score;

    return 0;
}
