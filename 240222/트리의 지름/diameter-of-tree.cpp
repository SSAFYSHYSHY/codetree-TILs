#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

int n;
vector<pair<int, int>> v[100001];
int arr[100001];
int sum[100001];

bool visited[100001];

int s_p[100001];
int e_p[100001];
int w_p[100001];

int m_len = 0;
int mp_len = 0;

void clear() {
	for (int i = 1; i <= n; i++) {
		visited[i] = false;
	}
}

void DFS(int x, int len) {
	//v 사이즈 별로 진행.
	if (!visited[x]) {
		visited[x] = true;

		if (m_len < len) {
			m_len = len;
			mp_len = x;
		}

		for (auto& v : v[x]) {
			int y = v.first;
			int w = v.second;

			DFS(y, len + w);
		}
	}
}

int main() {
	cin >> n;

	for (int i = 1; i < n; i++) {
		cin >> s_p[i] >> e_p[i] >> w_p[i];
	}

	for (int i = 1; i <= n - 1; i++) {
		int x = s_p[i];
		int y = e_p[i];
		int w = w_p[i];

		v[x].push_back(make_pair(y, w));
		v[y].push_back(make_pair(x, w));
	}

	clear();
	DFS(1, 0);

	clear();
	DFS(mp_len , 0);
	//자식 노드 순회해서 2 부터의 연산된 합을 구한다.
	cout << m_len << "\n";
}