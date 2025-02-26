#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k, start_x;
int cnt = 0;
vector<int> v[100001];
bool visited[100001];

void DFS(int x) {

	//리프 노드이면 cnt++;
	if (v[x].size() == 0) cnt++;

	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];

		//가고자 하는 위치가 k 이면 continue; 볼 필요도 없음.
		if (y == k) continue;
	
		if (!visited[y]) {
			visited[y] = true;
			DFS(y);
		}
	}
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

	visited[start_x] = 1;
	DFS(start_x);

	cout << cnt;
}