#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[30][30];
int new_arr[30][30];
bool visited[30][30];
int arr_num[30][30];
int ans = 0;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

struct GroupInfo {
    int idx, num, cnt;
};
vector<GroupInfo> v;
int idx = 1;

void Input() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> arr[i][j];
}

bool InRange(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < n;
}

void BFS(int idx, int sx, int sy, int num) {
    queue<pair<int, int>> q;
    q.push({ sx, sy });
    visited[sx][sy] = true;
    arr_num[sx][sy] = idx;
    int cnt = 1;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (!InRange(nx, ny)) continue;
            if (!visited[nx][ny] && arr[nx][ny] == num) {
                visited[nx][ny] = true;
                arr_num[nx][ny] = idx;
                q.push({ nx, ny });
                cnt++;
            }
        }
    }
    v.push_back({ idx, num, cnt });
}

void Group() {
    memset(visited, 0, sizeof(visited));
    memset(arr_num, 0, sizeof(arr_num));
    v.clear();
    idx = 1;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (!visited[i][j]) BFS(idx++, i, j, arr[i][j]);
}

int CountAdjacent(int a_idx, int b_idx) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (arr_num[i][j] != a_idx) continue;
            for (int d = 0; d < 4; ++d) {
                int ni = i + dx[d], nj = j + dy[d];
                if (!InRange(ni, nj)) continue;
                if (arr_num[ni][nj] == b_idx) cnt++;
            }
        }
    }
    return cnt;
}

void CalcScore() {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = i + 1; j < v.size(); ++j) {
            int border = CountAdjacent(v[i].idx, v[j].idx);
            ans += border * (v[i].cnt + v[j].cnt) * v[i].num * v[j].num;
        }
    }
}

void RotateSubgrid(int x, int y, int m) {
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < m; ++j)
            new_arr[x + j][y + m - 1 - i] = arr[x + i][y + j];
}

void Rotate() {
    int m = n / 2;
    memset(new_arr, 0, sizeof(new_arr));

    // 4 사분면
    RotateSubgrid(0, 0, m);
    RotateSubgrid(0, m + 1, m);
    RotateSubgrid(m + 1, 0, m);
    RotateSubgrid(m + 1, m + 1, m);

    // 십자 회전
    for (int i = 0; i < n; ++i) {
        new_arr[i][m] = arr[m][n - 1 - i];
        new_arr[m][i] = arr[i][m];
    }

    memcpy(arr, new_arr, sizeof(arr));
}

int main() {
    Input();
    for (int i = 0; i < 4; ++i) {
        Group();
        CalcScore();
        if (i < 3) Rotate();
    }
    cout << ans;
    return 0;
}