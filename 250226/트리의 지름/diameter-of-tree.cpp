#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[100001];
vector<pair<int, int>> v[100001];
int n, ans = 0;

void Input() {
	cin >> n;

	for (int i = 1; i <= n - 1; i++) {
		int x, y, w;
		cin >> x >> y >> w;

		v[x].push_back({ y,w });
		v[y].push_back({ x,w });
	}
}

void DFS(int num, int sum) {

	for (int i = 0; i < v[num].size(); i++) {
		int y = v[num][i].first;
		int cost = v[num][i].second;

		if (!visited[y]) {
			visited[y] = true;
			sum += cost;

			if(sum >= cost) {
				ans = max(sum, ans);
				DFS(y, sum);
			}

			sum -= cost;
			visited[y] = false;
		}

	}
}

int main() {
	Input();

	//초기화.
	visited[1] = true;
	DFS(1, 0);

	cout << ans;
}
