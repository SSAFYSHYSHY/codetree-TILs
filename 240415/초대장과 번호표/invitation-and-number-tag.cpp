#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>

using namespace std;

int n, g;
bool visited[100001];

unordered_set<int> us[250001];

vector<int> v[100001];
queue<int> q;

int ans;

int main() {
	cin >> n >> g;

	for (int i = 0; i < g; i++) {
		int s, x;
		cin >> s;

		for (int j = 0; j < s; j++) {
			cin >> x;
			x--;

			us[i].insert(x);
			v[x].push_back(i);
		}
	}

	q.push(0);
	visited[0] = true;

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		ans++;

		for (int i = 0; i < v[x].size(); i++) {
			int num = v[x][i];
			us[num].erase(x);

			if (us[num].size() == 1) {
				int p_num = *(us[num].begin());
				if (!visited[p_num]) {
					visited[p_num] = true;
					q.push(p_num);
				}
			}
		}

	}

	cout << ans;
}