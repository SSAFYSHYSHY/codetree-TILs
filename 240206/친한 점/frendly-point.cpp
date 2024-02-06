#include <iostream>
#include <set>

using namespace std;

set<pair<int, int>> v;
int n, m;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		v.insert(make_pair(x, y));
	}

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		auto p = v.lower_bound(make_pair(x, y));

		if (p == v.end()) {
			cout << "-1 -1\n";
		}
        else{
		    cout << p->first << " " << p->second << "\n";
        }
	}
}