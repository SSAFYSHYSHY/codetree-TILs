#include <iostream>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int n, m;
priority_queue<tuple<int,int,int>> q;
vector<pair<int, int>> v;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		v.push_back(make_pair(x, y));
	}

	for (int i = 0; i < n; i++) {
		int x = v[i].first;
		int y = v[i].second;
		q.push(make_tuple(-(x + y), -x, -y));
	}

	while (m--) {
		int x, y;
		tie(ignore, x, y) = q.top();
		q.pop();

		x = -x;
		y = -y;

		x += 2;
		y += 2;

		q.push(make_tuple(-(x + y), -x, -y));
	}

	int ax, ay;
	tuple<int, int, int> ans = q.top();

	tie(ignore, ax, ay) = ans;

	cout << -ax << " " << -ay;

}