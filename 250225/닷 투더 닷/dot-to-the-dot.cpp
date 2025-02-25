#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
#include <climits>

#define MAX_N 500

using namespace std;

// 변수 선언
int n, m, x;
vector<tuple<int, int, int> > graph[MAX_N + 1];
priority_queue<pair<int, int> > pq;

vector<int> c_list;
int dist[MAX_N + 1];

double ans = 1e9;

void Dijkstra(int k, int c_limit) {
    for (int i = 1; i <= n; i++)
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
            int target_index, target_l, target_c;
            tie(target_index, target_l, target_c) = graph[min_index][j];

            if (target_c < c_limit)
                continue;

            int new_dist = dist[min_index] + target_l;
            if (dist[target_index] > new_dist) {
                dist[target_index] = new_dist;
                pq.push(make_pair(-new_dist, target_index));
            }
        }
    }
}

int main() {
    cin >> n >> m >> x;

    while (m--) {
        int x, y, l, c;
        cin >> x >> y >> l >> c;
        graph[x].push_back(make_tuple(y, l, c));
        graph[y].push_back(make_tuple(x, l, c));

        c_list.push_back(c);
    }

    for (int i = 0; i < (int)c_list.size(); i++) {
        int c_limit = c_list[i];
        Dijkstra(1, c_limit);

        ans = min(ans, dist[n] + (double)x / c_limit);
    }

    cout << (int)ans;
    return 0;
}
