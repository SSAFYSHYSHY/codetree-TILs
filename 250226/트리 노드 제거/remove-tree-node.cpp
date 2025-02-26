#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k, start_x;
int cnt = 0;
vector<int> v[100001];
bool visited[100001];

void DFS(int x) {
	//리프 노드 판별
	bool isLeaf = true;
	visited[x] = true;

	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];

		if (!visited[y]) {
			isLeaf = false;
			DFS(y);
		}
	}

	if (isLeaf) cnt++;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (num == -1) {
			start_x = i;
		}
		else {
			v[num].push_back(i);
		}
	}
	cin >> k;

	if (k == start_x) {
		cout << 0;
		return 0;
	}

	visited[k] = 1;
	DFS(start_x);

	cout << cnt;
}