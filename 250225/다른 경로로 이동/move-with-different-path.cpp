#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 1000

using namespace std;

int n, m;
int graph[MAX_N + 1][MAX_N + 1];
bool visited[MAX_N + 1];
int dist[MAX_N + 1];

void Dijkstra(int k) {
    for (int i = 1; i <= n; i++)
        dist[i] = (int)1e9;

    dist[k] = 0;

    for (int i = 1; i <= n; i++)
        visited[i] = false;

    for (int i = 1; i <= n; i++) {
        int min_index = -1;
        for (int j = 1; j <= n; j++) {
            if (visited[j])
                continue;

            if (min_index == -1 || dist[min_index] > dist[j])
                min_index = j;
        }

        visited[min_index] = true;

        for (int j = 1; j <= n; j++) {
            if (graph[min_index][j] == 0)
                continue;

            if (dist[j] > dist[min_index] + graph[min_index][j]) {
                dist[j] = dist[min_index] + graph[min_index][j];
            }
        }
    }
}

int main() {
    cin >> n >> m;

    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        graph[x][y] = z;
        graph[y][x] = z;
    }

    Dijkstra(n);

    int x = 1;
    vector<int> vertices;
    vertices.push_back(x);
    while (x != n) {
        for (int i = 1; i <= n; i++) {
            if (graph[i][x] == 0)
                continue;

            if (dist[i] + graph[i][x] == dist[x]) {
                x = i;
                break;
            }
        }
        vertices.push_back(x);
    }

    for (int i = 0; i < (int)vertices.size() - 1; i++) {
        int x = vertices[i];
        int y = vertices[i + 1];
        graph[x][y] = 0;
        graph[y][x] = 0;
    }

    Dijkstra(1);

    int ans = dist[n];
    if (ans == (int)1e9)
        ans = -1;

    cout << ans;
    return 0;
}
