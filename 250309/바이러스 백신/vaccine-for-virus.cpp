#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

struct Node {
    int x, y, time;
};

int n, m;
int arr[51][51];
bool visited[51][51];

vector<pair<int, int>> virus;
vector<int> selected;
bool is_selected[11];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int bfs() {
    memset(visited, false, sizeof(visited));
    queue<Node> q;

    int total_empty = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0) total_empty++;
        }
    }

    for (int i = 0; i < selected.size(); i++) {
        int x = virus[selected[i]].first;
        int y = virus[selected[i]].second;
        visited[x][y] = true;
        q.push({ x, y, 0 });
    }

    int infected = 0;
    int time = 0;

    while (!q.empty()) {
        Node cur = q.front(); q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = cur.x + dx[d];
            int ny = cur.y + dy[d];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
            if (visited[nx][ny] || arr[nx][ny] == 1) continue;

            visited[nx][ny] = true;
            if (arr[nx][ny] == 0) {
                infected++;
                time = max(time, cur.time + 1);
            }
            q.push({ nx, ny, cur.time + 1 });
        }
    }

    if (infected == total_empty) return time;
    else return 1e9;
}

int ans = 1e9;
void backtrack(int idx, int cnt) {
    if (cnt == m) {
        ans = min(ans, bfs());
        return;
    }

    for (int i = idx; i < virus.size(); i++) {
        if (!is_selected[i]) {
            is_selected[i] = true;
            selected.push_back(i);
            backtrack(i + 1, cnt + 1);
            selected.pop_back();
            is_selected[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 2) virus.push_back({ i, j });
        }
    }

    backtrack(0, 0);

    if (ans == 1e9) cout << -1;
    else cout << ans;

    return 0;
}