#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX_L 41

int l, n, q;
int board[MAX_L][MAX_L];

struct Piece {
    int r, c, h, w, k;
    int init_k;
    int nr, nc;
    int dmg;
    bool is_moved;
};

vector<Piece> pieces;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool TryMove(int idx, int dir) {
    for (int i = 1; i <= n; i++) {
        pieces[i].nr = pieces[i].r;
        pieces[i].nc = pieces[i].c;
        pieces[i].dmg = 0;
        pieces[i].is_moved = false;
    }

    queue<int> q;
    q.push(idx);
    pieces[idx].is_moved = true;

    while (!q.empty()) {
        int x = q.front(); q.pop();
        Piece &p = pieces[x];

        p.nr += dx[dir];
        p.nc += dy[dir];

        // 경계 체크
        if (p.nr < 1 || p.nc < 1 || p.nr + p.h - 1 > l || p.nc + p.w - 1 > l)
            return false;

        // 장애물 체크 및 데미지 계산
        for (int i = p.nr; i < p.nr + p.h; i++) {
            for (int j = p.nc; j < p.nc + p.w; j++) {
                if (board[i][j] == 2) return false;
                if (board[i][j] == 1) p.dmg++;
            }
        }

        // 다른 조각과 겹침 체크
        for (int i = 1; i <= n; i++) {
            if (pieces[i].k <= 0 || pieces[i].is_moved || i == x) continue;

            Piece &p2 = pieces[i];

            if (p.nr + p.h - 1 < p2.r || p2.r + p2.h - 1 < p.nr ||
                p.nc + p.w - 1 < p2.c || p2.c + p2.w - 1 < p.nc)
                continue;

            pieces[i].is_moved = true;
            q.push(i);
        }
    }

    pieces[idx].dmg = 0; // 시작 조각은 데미지 없음
    return true;
}

void MovePiece(int idx, int dir) {
    if (pieces[idx].k <= 0) return;

    if (TryMove(idx, dir)) {
        for (int i = 1; i <= n; i++) {
            if (pieces[i].is_moved && pieces[i].k > 0) {
                pieces[i].r = pieces[i].nr;
                pieces[i].c = pieces[i].nc;
                pieces[i].k -= pieces[i].dmg;
                if (pieces[i].k < 0) pieces[i].k = 0;
            }
        }
    }
}

int main() {
    cin >> l >> n >> q;

    for (int i = 1; i <= l; i++)
        for (int j = 1; j <= l; j++)
            cin >> board[i][j];

    pieces.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> pieces[i].r >> pieces[i].c >> pieces[i].h >> pieces[i].w >> pieces[i].k;
        pieces[i].init_k = pieces[i].k;
    }

    for (int i = 0; i < q; i++) {
        int idx, dir;
        cin >> idx >> dir;
        MovePiece(idx, dir);
    }

    long long result = 0;
    for (int i = 1; i <= n; i++) {
        if (pieces[i].k > 0)
            result += pieces[i].init_k - pieces[i].k;
    }
    cout << result;
    return 0;
}
