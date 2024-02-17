#include <iostream>
#include <set>	
#include <vector>
#include <algorithm>
#include <climits>
#include <tuple>

using namespace std;

set<pair<int, int>>s;

int main(void) {
	int n, m;
	cin >> n >> m;

	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		s.insert(make_pair(x, y));
	}

	int k;
	for (int i = 0; i < m; i++) {
		cin >> k;
		if (s.lower_bound(make_pair(k,-1)) == s.end()) {
			cout << "-1 -1" << "\n";
		}
		else {
			pair<int, int>tmp = *s.lower_bound(make_pair(k, -1));
			int x, y;
			tie(x, y) = tmp;
			cout << x << " " << y << "\n";
			s.erase(tmp);
		}
	}
	return 0;
}