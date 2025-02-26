#include <iostream>
#include <vector>
#include <cstring> // memset 사용
#define MAX_N 1001

using namespace std;

int n, m;
vector<pair<int, int>> v[MAX_N];
bool visited[MAX_N];
int dist[MAX_N];

void Input() {
    cin >> n >> m;

    for (int i = 0; i < n - 1; i++) {
        int x, y, w;
        cin >> x >> y >> w;

        v[x].push_back({ y, w });
        v[y].push_back({ x, w });
    }
}

void DFS(int start, int endi) {
    if (start == endi) return;

    for (auto &next : v[start]) {
        int y = next.first;
        int cost = next.second;

        if (!visited[y]) {
            visited[y] = true;
            dist[y] = dist[start] + cost;
            DFS(y, endi);
        }
    }
}

int Calc(int start, int endi) {
    memset(visited, false, sizeof(visited));
    memset(dist, 0, sizeof(dist));

    visited[start] = true;
    dist[start] = 0;
    DFS(start, endi);

    return dist[endi];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Input();

    for (int i = 0; i < m; i++) {
        int s, e;
        cin >> s >> e;
        cout << Calc(s, e) << "\n";
    }
}
