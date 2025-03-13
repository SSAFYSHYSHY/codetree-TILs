#include <iostream>
#include <queue>
using namespace std;

#define MAX_L 41
#define MAX_N 31

int l, n, q;
int info[MAX_L][MAX_L];

struct Piece {
    int r, c, h, w, k;     // 위치 (r, c), 크기 (h, w), 체력
    int init_k;            // 초기 체력 저장
    int dmg;               // 이동 시 받는 데미지
    bool isMoved;          // 이동 여부
    int nr, nc;            // 임시 위치
} pieces[MAX_N];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

// 이동 가능한지 확인하는 함수
bool TryMovement(int idx, int dir) {
    for (int i = 1; i <= n; i++) {
        pieces[i].dmg = 0;
        pieces[i].isMoved = false;
        pieces[i].nr = pieces[i].r;
        pieces[i].nc = pieces[i].c;
    }

    queue<int> q;
    q.push(idx);
    pieces[idx].isMoved = true;

    while (!q.empty()) {
        int x = q.front(); q.pop();

        pieces[x].nr += dx[dir];
        pieces[x].nc += dy[dir];

        // 경계 체크
        if (pieces[x].nr < 1 || pieces[x].nc < 1 ||
            pieces[x].nr + pieces[x].h - 1 > l ||
            pieces[x].nc + pieces[x].w - 1 > l)
            return false;

        // 장애물 및 덫 체크
        for (int i = pieces[x].nr; i <= pieces[x].nr + pieces[x].h - 1; i++) {
            for (int j = pieces[x].nc; j <= pieces[x].nc + pieces[x].w - 1; j++) {
                if (info[i][j] == 1)
                    pieces[x].dmg++;
                if (info[i][j] == 2)
                    return false;
            }
        }

        // 다른 말과 충돌 체크
        for (int i = 1; i <= n; i++) {
            if (pieces[i].isMoved || pieces[i].k <= 0)
                continue;
            if (pieces[i].r > pieces[x].nr + pieces[x].h - 1 || 
                pieces[i].nr > pieces[i].r + pieces[i].h - 1)
                continue;
            if (pieces[i].c > pieces[x].nc + pieces[x].w - 1 ||
                pieces[i].nc > pieces[i].c + pieces[i].w - 1)
                continue;

            pieces[i].isMoved = true;
            q.push(i);
        }
    }

    pieces[idx].dmg = 0; // 본인 덫 데미지는 무시
    return true;
}

// 실제 이동 수행 함수
void MovePiece(int idx, int dir) {
    if (pieces[idx].k <= 0) return;

    if (TryMovement(idx, dir)) {
        for (int i = 1; i <= n; i++) {
            if (!pieces[i].isMoved) continue;
            pieces[i].r = pieces[i].nr;
            pieces[i].c = pieces[i].nc;
            pieces[i].k -= pieces[i].dmg;
            if (pieces[i].k < 0) pieces[i].k = 0;
        }
    }
}

int main() {
    cin >> l >> n >> q;

    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= l; j++) {
            cin >> info[i][j];
        }
    }

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

    cout << result << "\n";
    return 0;
}
