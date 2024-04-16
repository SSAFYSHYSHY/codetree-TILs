#include <iostream>
#include <set>
#include <string>

using namespace std;

int t, k;
set<int> v;

int main() {
	cin >> t;

	while (t--) {
		cin >> k;

		for (int i = 0; i < k; i++) {
			char c;
			cin >> c;

			if (c == 'I') {
				int num;
				cin >> num;

				v.insert(num);
			}
			else if(c == 'D') {
				int num;
				cin >> num;

				if (num == 1 && !v.empty()) {
					v.erase(*v.rbegin());
				}
				else if(num == -1 && !v.empty()){
					v.erase(*v.begin());
				}
			}
		}

		if (v.empty()) {
			cout << "EMPTY\n";
		}
		else {
			cout << *v.rbegin() << " " << *v.begin() << "\n";
		}
		v.clear();
	}
}