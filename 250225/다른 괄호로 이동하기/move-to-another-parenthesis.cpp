#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

#define MAX_N 30
#define MAX_M 900
#define DIR_NUM 4

using namespace std;

// 변수 선언
int n, m, a, b;
char brackets[MAX_N + 1][MAX_N + 1];
int node_num[MAX_N + 1][MAX_N + 1];
vector<pair<int, int> > graph[MAX_M + 1];
priority_queue<pair<int, int> > pq;

int dist[MAX_M + 1];
int ans;

bool InRange(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= n;
}

void MakeGraph() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            node_num[i][j] = ++m;

    for (int x = 1; x <= n; x++)
        for (int y = 1; y <= n; y++) {
            int dx[DIR_NUM] = { -1, 1,  0, 0 };
            int dy[DIR_NUM] = { 0, 0, -1, 1 };

            for (int k = 0; k < DIR_NUM; k++) {
                int nx = x + dx[k], ny = y + dy[k];
                if (InRange(nx, ny)) {
                    int node1 = node_num[x][y];
                    int node2 = node_num[nx][ny];
                    int cost = (brackets[x][y] == brackets[nx][ny]) ? a : b;
                    graph[node1].push_back(make_pair(node2, cost));
                }
            }
        }
}

void Dijkstra(int k) {
    for (int i = 1; i <= m; i++)
        dist[i] = (int)1e9;

    dist[k] = 0;

    pq.push(make_pair(-0, k));

    while (!pq.empty()) {
        int min_dist, min_index;
        tie(min_dist, min_index) = pq.top();
        pq.pop();

        min_dist = -min_dist;

        if (min_dist != dist[min_index])
            continue;

        for (int j = 0; j < (int)graph[min_index].size(); j++) {
            int target_index, target_dist;
            tie(target_index, target_dist) = graph[min_index][j];

            int new_dist = dist[min_index] + target_dist;
            if (dist[target_index] > new_dist) {
                dist[target_index] = new_dist;
                pq.push(make_pair(-new_dist, target_index));
            }
        }
    }
}

int main() {
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> brackets[i][j];

    MakeGraph();

    for (int i = 1; i <= m; i++) {
        Dijkstra(i);
        for (int j = 1; j <= m; j++)
            ans = max(ans, dist[j]);
    }

    cout << ans;
    return 0;
}
