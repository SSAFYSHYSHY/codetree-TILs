#include <iostream>
#include <set>
#include <tuple>

using namespace std;

int n, m;
set<pair<int, int>> s;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		s.insert(make_pair(x, y));
	}

	for (int i = 0; i < m; i++) {
		int k;

		cin >> k;

		if (s.upper_bound(make_pair(k, -1)) == s.end()) {
			cout << "-1 -1\n";
		}
		else {
			pair<int, int> p = *s.upper_bound(make_pair(k, -1));

			int x, y;
			tie(x, y) = p;

			cout << x << " " << y << "\n";
			s.erase(p);
		}
	}
}