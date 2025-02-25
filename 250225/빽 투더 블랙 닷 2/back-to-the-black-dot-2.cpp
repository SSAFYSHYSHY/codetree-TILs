#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
#include <climits>

#define MAX_N 100000

using namespace std;

// 변수 선언
int n, m;
int a, b;
vector<pair<int, int> > graph[MAX_N + 1];
priority_queue<pair<int, int> > pq;

int red_dist1[MAX_N + 1];
int red_dist2[MAX_N + 1];

int ans = INT_MAX;

void Dijkstra(int k, int dist[]) {
    for (int i = 1; i <= n; i++)
        dist[i] = (int)1e8;

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
    // 입력
    cin >> n >> m;
    cin >> a >> b;

    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].push_back(make_pair(y, z));
        graph[y].push_back(make_pair(x, z));
    }

    Dijkstra(a, red_dist1);
    Dijkstra(b, red_dist2);

    for (int i = 1; i <= n; i++) {
        if (i == a || i == b)
            continue;

        if (red_dist1[i] != (int)1e8 && red_dist1[b] != (int)1e8
            && red_dist2[i] != (int)1e8)
            ans = min(ans, red_dist1[i] + red_dist1[b] + red_dist2[i]);

        if (red_dist2[i] != (int)1e8 && red_dist2[a] != (int)1e8
            && red_dist1[i] != (int)1e8)
            ans = min(ans, red_dist2[i] + red_dist2[a] + red_dist1[i]);
    }

    if (ans == INT_MAX)
        ans = -1;

    cout << ans;
    return 0;
}
