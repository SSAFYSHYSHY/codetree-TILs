#include <iostream>
#include <set>

using namespace std;

set<int> v;
int n, m;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.insert(a);
	}

	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;

		if (v.lower_bound(a) == v.end()) {
			cout << -1 << "\n";
		}
		else {
			cout << *v.lower_bound(a) << "\n";
		}
	}
}