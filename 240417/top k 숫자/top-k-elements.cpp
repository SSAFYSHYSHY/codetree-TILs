#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int k, n;
set<int> s;

int main() {
	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		int a;
		cin >> a;

		s.insert(a);
	}

	for (int i = 0; i < n; i++) {
		cout << *s.rbegin() << " ";

		s.erase(*s.rbegin());
	}
}