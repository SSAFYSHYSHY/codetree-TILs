#include <iostream>
#include <set>

using namespace std;

int n;
set<int> v;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string a;
		cin >> a;

		if (a == "add") {
			int num;
			cin >> num;

			v.insert(num);
		}
		else if (a == "remove") {
			int num;
			cin >> num;

			v.erase(num);
		}
		else if (a == "find") {
			int num;
			cin >> num;

			if (v.find(num) != v.end()) {
				cout << "true\n";
			}
			else {
				cout << "false\n";
			}
		}
		else if (a == "lower_bound") {
			int num;
			cin >> num;

			if (v.lower_bound(num) == v.end()) {
				cout << "None\n";
			}
			else {
				cout << *v.lower_bound(num) << "\n";
			}
		}
		else if (a == "upper_bound") {
			int num;
			cin >> num;

			if (v.upper_bound(num) == v.end()) {
				cout << "None\n";
			}
			else {
				cout << *v.upper_bound(num) << "\n";
			}
		}
		else if (a == "largest") {
			if (v.empty()) {
				cout << "None\n";
			}
			else {
				cout << *v.rbegin() << "\n";
			}
		}
		else if (a == "smallest") {
			if (v.empty()) {
				cout << "None\n";
			}
			else {
				cout << *v.begin() << "\n";
			}
		}


	}


}