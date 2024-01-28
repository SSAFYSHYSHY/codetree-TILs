#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, s;

//BFS 탐색.
vector<int> v[1001];
queue<int> q;
bool visited[1001] = {false,};
bool visited1[1001] = { false, };

vector<int> a_d;
vector<int> a_b;

void DFS(int num) {
	visited1[num] = true;
	cout << num << " ";

	for (int i = 0; i < v[num].size(); i++) {
		int curr = v[num][i];
		if (!visited1[curr]) {
			DFS(curr);
		}
	}
}

void BFS(int num) {
	visited[num] = true;
	q.push(num);

	while (!q.empty()) {
		int num = q.front();
		q.pop();
		cout << num << " ";

		for (int i = 0; i < v[num].size(); i++) {
			int y = v[num][i];
			if (!visited[y]) {
				visited[y] = true;
				q.push(y);
			}
		}
	}
} 

int main() {
	cin >> n >> m >> s;

	for (int i = 0; i < m; i++) {
		int st, en;
		cin >> st >> en;

		v[st].push_back(en);
		v[en].push_back(st);
	}

	DFS(s);

	cout << "\n";

	BFS(s);

}