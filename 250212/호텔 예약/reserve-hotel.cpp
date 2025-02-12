#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int n;

vector<pair<int, int>> points, seg;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		seg.push_back({ x,y });
	}

	for (int i = 0; i < n; i++) {
		int x1, x2;
		tie(x1, x2) = seg[i];

		points.push_back({ x1, +1 });
		points.push_back({ x2 + 1, -1 });
	}

	sort(points.begin(), points.end());

	int sum_val = 0, ans = 0;
	for (int i = 0; i < 2 * n; i++) {
		int x, v;
		tie(x, v) = points[i];

		sum_val += v;

		ans = max(ans, sum_val);
	}

	cout << ans;
}