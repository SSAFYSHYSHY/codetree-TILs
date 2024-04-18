#include <iostream>
#include <set>

using namespace std;

int n, m;
set<int> s;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		s.insert(a);
	}

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;

		set<int>::iterator it = s.upper_bound(num);

		if (it == s.begin()) {
			cout << -1 << "\n";
		}
		else {
			it--;
			cout << *it << "\n";
			s.erase(*it);
		}

	}



}