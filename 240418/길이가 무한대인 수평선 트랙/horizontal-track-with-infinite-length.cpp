#include <iostream>
#include <set>
#include <tuple>

using namespace std;

int n, t;
set<pair<int, int>> s;
set<tuple<double, int, int>> st;

int x[100001];
int v[100001];

void Add(int x1, int v1, int x2, int v2) {
	if (v1 <= v2) {
		return;
	}

	st.insert(make_tuple(1.0 * (x2 - x1) / (v1 - v2), x1, v1));
}

void Remove(int x1, int y1, int x2, int y2) {
	if (y1 <= y2) {
		return;
	}

	st.erase(make_tuple(1.0 * (x2 - x1) / (y2 - y1), x1, y1));
}

int main() {
	cin >> n >> t;

	for (int i = 0; i < n; i++) {
		cin >> x[i] >> v[i];
	}

	for (int i = 0; i < n - 1; i++) {
		Add(x[i], v[i], x[i + 1], v[i + 1]);
	}

	while (!st.empty()) {
		double curr_t;
		int x, v;
		tie(curr_t, x, v) = *st.begin();

		if (curr_t > t) {
			break;
		}

		s.erase(make_pair(x, v));
		st.erase(make_tuple(curr_t, x, v));

		set<pair<int, int>>::iterator it = s.upper_bound(make_pair(x, v));

		int nx, ny;
		tie(nx, ny) = *it;

		if (it != s.begin()) {
			it--;
			int px, py;
			tie(px, py) = *it;
			Remove(px, py, x, v);
			Add(px, py, nx, ny);
		}
	}

	cout << s.size();
}