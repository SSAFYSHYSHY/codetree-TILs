#include <iostream>
#include <vector>
#include <tuple>

#define MAX_N 100000

using namespace std;

int n;
vector<pair<int, int> > edges[MAX_N + 1];
bool visited[MAX_N + 1];
int dist[MAX_N + 1];

void DFS(int x, int total_dist) {
    for (int i = 0; i < (int)edges[x].size(); i++) {
        int y, d;
        tie(y, d) = edges[x][i];
        if (!visited[y]) {
            visited[y] = true;
            dist[y] = total_dist + d;
            DFS(y, total_dist + d);
        }
    }
}

pair<int, int> FindLargestVertex(int x) {
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
        dist[i] = 0;
    }

    visited[x] = true;
    dist[x] = 0;
    DFS(x, 0);

    int farthest_dist = -1;
    int farthest_vertex = -1;
    for (int i = 1; i <= n; i++) {
        if (dist[i] > farthest_dist) {
            farthest_dist = dist[i];
            farthest_vertex = i;
        }
    }

    return make_pair(farthest_vertex, farthest_dist);
}

int main() {
    cin >> n;

    for (int i = 1; i <= n - 1; i++) {
        int x, y, d;
        cin >> x >> y >> d;

        edges[x].push_back(make_pair(y, d));
        edges[y].push_back(make_pair(x, d));
    }

    int f_vertex;
    tie(f_vertex, ignore) = FindLargestVertex(1);

    int diameter;
    tie(ignore, diameter) = FindLargestVertex(f_vertex);

    cout << diameter;
    return 0;
}
