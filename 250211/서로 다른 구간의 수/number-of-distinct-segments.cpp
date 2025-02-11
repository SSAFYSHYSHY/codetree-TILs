#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int n;
vector<tuple<int, int, int>> points;
pair<int, int> arr[100001];

void Input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		arr[i].first = x;
		arr[i].second = y;
	}
}

int main() {
	Input();

	//+1,-1 을 연산, x , +1,-1, idx
	for (int i = 0; i < n; i++) {
		int x1, x2;
		tie(x1, x2) = arr[i];

		points.push_back({ x1, +1, i });
		points.push_back({ x2, -1, i });
	}
	//정렬.
	sort(points.begin(), points.end());

	int ans = 0;
	unordered_set<int> segs;
	for (int i = 0; i < 2 * n; i++) {
		int x, v, idx;
		tie(x, v, idx) = points[i];

		if (v == +1) {
			if ((int)segs.size() == 0) {
				ans++;
			}

			segs.insert(idx);
		}
		else {
			segs.erase(idx);
		}
	}

	cout << ans;
}