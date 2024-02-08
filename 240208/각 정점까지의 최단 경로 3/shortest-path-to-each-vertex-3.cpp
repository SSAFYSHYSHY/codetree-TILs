#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <tuple>
#include <climits>

using namespace std;

int arr[6][6];
bool visited[6];
int dist[6];
vector<tuple<int, int, int>> v;

int main() {
	//정점의 개수, 간선의 수.
	int n, m, k;

	cin >> n >> m;

	//v.push_back(make_tuple(-1, -1, -1));
	for (int i = 0; i < m; i++) {
		//x -> y 로 가는 간선과, w 가중치의 값.
		int x, y, w;
		cin >> x >> y >> w;
		v.push_back(make_tuple(x, y, w));
		arr[x][y] = w;
	}

	for (int i = 1; i <= n; i++) {
		dist[i] = 1e9;
	}
	dist[1] = 0;

	//1 번 부터 n 번까지 방문.
	for (int i = 1; i <= n; i++) {
		//V개의 정점중, 아직 방문하지 않은 값 중 dist 값이 아주 작은 값.
		int min_idx = -1;

		for (int j = 1; j <= n; j++) {
			if (visited[j]) continue;

			if (min_idx == -1 || dist[min_idx] > dist[j]) {
				min_idx = j;
			}
		}

		visited[min_idx] = true;

		for (int j = 1; j <= n; j++) {
			if (arr[min_idx][j] == 0) {
				continue;
			}

			dist[j] = min(dist[j], dist[min_idx] + arr[min_idx][j]);
		}
	}

	for (int i = 2; i <= n; i++) {
		if (dist[i] == 1e9) {
			cout << -1 << "\n";
		}
		else {
			cout << dist[i] << "\n";
		}
	}


}