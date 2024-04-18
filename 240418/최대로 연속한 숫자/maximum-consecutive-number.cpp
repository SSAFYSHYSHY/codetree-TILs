#include <iostream>
#include <set>
#include <tuple>

using namespace std;

int n, m;
set<int> s;
set<tuple<int, int, int>> s2;

int main() {
	cin >> n >> m;

	s.insert(-1);
	s.insert(n + 1);

	s2.insert(make_tuple(-(n + 1), -1, n + 1));

	for (int i = 0; i < m; i++) {
		int y;
		cin >> y;

		s.insert(y);

		set<int>::iterator it;

		it = s.find(y);
		it++;
		int z = *it;

		it = s.find(y);
		it--;
		int x = *it;

		s2.erase(make_tuple(-(z - x - 1), x, z));
		s2.insert(make_tuple(-(y - x - 1), x, y));
		s2.insert(make_tuple(-(z - y - 1), y, z));

		int best_len;
		tie(best_len, ignore, ignore) = *s2.begin();

		cout << -best_len << "\n";
	}

}