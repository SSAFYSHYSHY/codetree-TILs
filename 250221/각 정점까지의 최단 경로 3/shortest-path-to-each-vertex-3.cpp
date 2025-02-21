#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int n, m;
int arr[101][101];
bool visited[101];
int dist[101];

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;

		arr[x][y] = z;
	}

	for (int i = 1; i <= n; i++) {
		dist[i] = (int)1e9;
	}
	dist[1] = 0;

	for (int i = 1; i <= n; i++) {
		int min_idx = -1;

		for (int j = 1; j <= n; j++) {
			if (visited[j]) continue;

			if (min_idx == -1 || dist[min_idx] > dist[j]) {
				min_idx = j;
			}
		}
		visited[min_idx] = true;

		for (int j = 1; j <= n; j++) {
			if (arr[min_idx][j] == 0) continue;

			dist[j] = min(dist[j], dist[min_idx] + arr[min_idx][j]);
		}

	}

	for (int i = 2; i <= n; i++) {
		if (dist[i] == (int)1e9) {
			cout << -1 << "\n";
		}
		else {
			cout << dist[i] << "\n";
		}
	}

}
