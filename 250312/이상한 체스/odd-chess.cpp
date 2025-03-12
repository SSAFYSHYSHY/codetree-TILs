#include <iostream>
#include <vector>
#include <climits>
#include <tuple>
#include <algorithm>
#include <cstring>

#define MAX_N 8
#define MAX_M 8
#define CHESS_TYPE_NUM 5
#define DIR_NUM 4

using namespace std;

int n, m;
int min_area = INT_MAX;
vector<pair<int, int> > chess_pieces;
int board[MAX_N][MAX_M];
int piece_dir[MAX_N][MAX_M];
bool visited[MAX_N][MAX_M];

bool can_move[CHESS_TYPE_NUM + 1][DIR_NUM] = {
    {},
    {1, 0, 0, 0},
    {0, 1, 0, 1},
    {1, 1, 0, 0},
    {1, 1, 0, 1},
    {1, 1, 1, 1}
};

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

bool CanGo(int x, int y) {
    return InRange(x, y) && board[x][y] != 6;
}

void Fill(int s_x, int s_y, int piece_num, int face_dir) {
    int dx[] = { -1,0,1,0 };
    int dy[] = { 0,1,0,-1 };

    for (int i = 0; i < 4; i++) {
        if (!can_move[piece_num][i]) continue;

        int x = s_x;
        int y = s_y;
        int move_dir = (i + face_dir) % 4;

        while (1) {
            visited[x][y] = true;
            int nx = x + dx[move_dir];
            int ny = y + dy[move_dir];

            if (CanGo(nx, ny)) {
                x = nx;
                y = ny;
            }
            else {
                break;
            }
        }
    }
}

int Calc() {
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < (int)chess_pieces.size(); i++) {
        int x, y;
        tie(x, y) = chess_pieces[i];

        Fill(x, y, board[x][y], piece_dir[x][y]);
    }

    int area = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == 0 && board[i][j] != 6) {
                area++;
            }
        }
    }

    return area;
}

void Back(int cnt) {
    if (cnt == (int)chess_pieces.size()) {
        min_area = min(min_area, Calc());
        return;
    }

    int p_x, p_y;
    tie(p_x, p_y) = chess_pieces[cnt];

    for (int i = 0; i < 4; i++) {
        piece_dir[p_x][p_y] = i;
        Back(cnt + 1);
    }
}

void Input() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];

            if (1 <= board[i][j] && board[i][j] <= 5) {
                chess_pieces.push_back({ i,j });
            }
        }
    }

    Back(0);
    cout << min_area;
}

int main() {
    Input();
}