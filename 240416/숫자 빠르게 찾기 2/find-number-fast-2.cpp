#include <iostream>
#include <set>

using namespace std;

int n, m;
set<int> v;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		v.insert(num);
	}

	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;

		if (v.lower_bound(a) != v.end()) {
			cout << *v.lower_bound(a) <<"\n";
		}
		else {
			cout << "-1\n";
		}
	}
}