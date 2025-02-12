#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;

int n, ans;

vector<pair<int, int>> segs;
int visited[100001];

priority_queue<int> pq;

void Input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x1, x2;
		cin >> x1 >> x2;

		segs.push_back(make_pair(x1, x2));
	}

	for (int i = 1; i <= n; i++) {
		pq.push(-i);
	}

	vector<tuple<int, int, int>> points;
	for (int i = 0; i < n; i++) {
		int x1, x2;
		tie(x1, x2) = segs[i];

		points.push_back({ x1, +1, i });
		points.push_back({ x2, -1,i });
	}
	sort(points.begin(), points.end());

	for(int i = 0; i < 2 * n ; i++) {
		int x, v, idx;
		tie(x, v, idx) = points[i];

		if (v == +1) {
			int sum = pq.top();
			pq.pop();

			visited[idx] = -sum;
		}
		else {
			int sum = visited[idx];
			pq.push(-sum);
		}
	}

	for (int i = 0; i < n; i++) {
		cout << visited[i] << " ";
	}
}

int main() {
	Input();
}
