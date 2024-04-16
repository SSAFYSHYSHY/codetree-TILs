#include <iostream>
#include <set>

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
		int a, b;
		cin >> a >> b;
		
		if (s.lower_bound(make_pair(a, b)) == s.end()) {
			cout << "-1 -1\n";
		}
		else {
			pair<int, int> p = *s.lower_bound(make_pair(a, b));
			cout << p.first << " " << p.second << "\n";
		}

	}

}