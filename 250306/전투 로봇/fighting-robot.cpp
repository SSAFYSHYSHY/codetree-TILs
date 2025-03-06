#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n, s_x, s_y, lv = 2, ans = 0, cnt = 0;
int arr[21][21];
bool visited[21][21];

struct Node {
    int x, y, num;
};

Node enemy[500];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void Input() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 9) {
                s_x = i;
                s_y = j;
                arr[i][j] = 0;
            }
            else if (arr[i][j] > 0) {
                enemy[cnt] = { i, j, arr[i][j] };
                cnt++;
            }
        }
    }
}

struct Info {
    int x, y, dist;
};

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool cmp(Info a, Info b) {
    if (a.dist != b.dist) return a.dist < b.dist; // 거리 우선
    if (a.x != b.x) return a.x < b.x;           // 행 작은 순
    return a.y < b.y;                           // 열 작은 순
}

pair<int, int> Find(int x, int y) {
    memset(visited, false, sizeof(visited));
    queue<pair<pair<int, int>, int>> q;
    q.push({ { x, y }, 0 });
    vector<Info> v;
    visited[x][y] = true;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        if (arr[x][y] > 0 && arr[x][y] < lv) { // 먹을 수 있는 적만 고려
            v.push_back({ x, y, dist });
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] <= lv) {
                q.push({ {nx, ny}, dist + 1 });
                visited[nx][ny] = true;
            }
        }
    }

    sort(v.begin(), v.end(), cmp);

    if (v.empty()) {
        return { -1, -1 };
    }

    return { v[0].x, v[0].y };
}

int BFS(int sx, int sy, int ex, int ey) {
    memset(visited, false, sizeof(visited));
    queue<pair<pair<int, int>, int>> q;
    q.push({ {sx, sy}, 0 });
    visited[sx][sy] = true;

    while (!q.empty()) {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        if (cx == ex && cy == ey) {
            s_x = ex;
            s_y = ey;
            return dist;
        }

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] <= lv) {
                q.push({ {nx, ny}, dist + 1 });
                visited[nx][ny] = true;
            }
        }
    }

    return -1;
}

int main() {
    Input();

    int eat_cnt = 0;
    while (true) {
        pair<int, int> p = Find(s_x, s_y);

        if (p.first == -1 && p.second == -1) {
            cout << ans;
            return 0;
        }

        int num = BFS(s_x, s_y, p.first, p.second);

        if (num == -1) {
            cout << ans;
            return 0;
        }

        arr[p.first][p.second] = 0; // BFS 후 적 제거
        ans += num;
        eat_cnt++;

        if (eat_cnt == lv) {
            eat_cnt = 0;
            lv++;
        }
    }
}
