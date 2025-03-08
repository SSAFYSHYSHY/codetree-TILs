#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct Virus {
    int x, y, s, d, b;
};

int n, m, k, ans = 0;
vector<Virus> viruses;

int dx[] = { 0, -1, 1, 0, 0 };
int dy[] = { 0, 0, 0, 1, -1 };

void Input() {
    cin >> n >> m >> k;
    viruses.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> viruses[i].x >> viruses[i].y >> viruses[i].s >> viruses[i].d >> viruses[i].b;
    }
}

bool InRange(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

int Find(int col) {
    for (auto& v : viruses) {
        if (v.y == col && v.x > 0) {
            int caught = v.b;
            v.x = v.y = -1; // 바이러스 제거 처리
            return caught;
        }
    }
    return 0;
}

void Move() {
    for (auto& v : viruses) {
        if (v.x == -1) continue;

        int x = v.x, y = v.y, s = v.s, d = v.d;

        for (int i = 0; i < s; i++) {
            x += dx[d];
            y += dy[d];

            if (!InRange(x, y)) {
                // 방향 반전
                d = (d == 1) ? 2 : (d == 2) ? 1 : (d == 3) ? 4 : 3;
                x += dx[d] * 2;
                y += dy[d] * 2;
            }
        }

        v.x = x;
        v.y = y;
        v.d = d;
    }
}

void Find_Destroy() {
    map<pair<int, int>, Virus> merged;

    for (auto& v : viruses) {
        if (v.x == -1) continue;

        pair<int, int> pos = { v.x, v.y };
        if (merged.find(pos) == merged.end() || merged[pos].b < v.b) {
            merged[pos] = v;
        }
    }

    viruses.clear();
    for (auto& it : merged) {
        viruses.push_back(it.second);
    }
}

int main() {
    Input();

    for (int i = 1; i <= m; i++) {
        ans += Find(i);
        Move();
        Find_Destroy();
    }

    cout << ans;
}
