#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, s;

//BFS 탐색.
vector<int> v[10001];
vector<int> v1[10001];
queue<int> q;
bool visited[10001] = {false,};
bool visited1[10001] = { false, };

vector<int> a_d;
vector<int> a_b;

void DFS(int num) {
	visited1[num] = true;
    //a_d.push_back(num);
    cout << num << " ";

    sort(v1[num].begin(), v1[num].end());
	for (int i = 0; i < v1[num].size(); i++) {
		int curr = v1[num][i];
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
        //a_b.push_back(num);
		cout << num << " ";
        q.pop();

        sort(v[num].begin(), v[num].end());

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

        v1[st].push_back(en);
        v1[en].push_back(st);
	}

	DFS(s);
    // for(int i = 0; i < a_d.size() ; i++) {
    //     cout << a_d[i] << " ";
    // }

    cout << "\n";
	BFS(s);
    // for(int i = 0; i < a_b.size() ; i++) {
    //     cout << a_b[i] << " ";
    // }


}