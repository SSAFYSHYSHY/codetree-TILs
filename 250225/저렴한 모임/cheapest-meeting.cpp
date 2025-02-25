#include <iostream>
#include <algorithm>

#define MAX_N 100

using namespace std;

int n, m;
int v1, v2, e;
int dist[MAX_N + 1][MAX_N + 1];

int main() {
    cin >> n >> m;
    cin >> v1 >> v2 >> e;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            dist[i][j] = (int)1e8;

        dist[i][i] = 0;
    }

    while (m--) {
        int x, y, z;
        cin >> x >> y >> z;
        dist[x][y] = dist[y][x] = z;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int ans = (int)1e8;
    for (int k = 1; k <= n; k++)
        ans = min(ans, dist[v1][k] + dist[v2][k] + dist[k][e]);

    if (ans == (int)1e8)
        ans = -1;

    cout << ans;
    return 0;
}
