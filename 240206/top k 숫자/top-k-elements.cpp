#include <iostream>
#include <set>

using namespace std;

set<int> s;
int n, k;

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		s.insert(a);
	}

	for (int i = 0; i < k; i++) {
		cout << *s.rbegin() << " ";

		s.erase(*s.rbegin());
	}
}