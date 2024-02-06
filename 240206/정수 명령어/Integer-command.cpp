#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int t, k;
set<int> v;

void Calc() {
	for (int i = 0; i < k; i++) {
		char c;
		int a;

		cin >> c;

		if (c == 'I') {
			cin >> a;

			v.insert(a);
		}
		else if (c == 'D') {
			cin >> a;

			if (a == 1 && !v.empty()) {
				int num = *v.rbegin();

				v.erase(num);
			}
			else if (a == -1 && !v.empty()) {
				int num = *v.begin();

				v.erase(num);
			}
		}

	}
}

void Print() {
	if (v.empty()) {
		cout << "EMPTY\n";
	}
	else {
		cout << *v.rbegin() << " " << *v.begin() << "\n";
	}
}

int main() {
	cin >> t;

	while (t--) {
		v.clear();
		cin >> k;

		Calc();

		Print();
	}
}