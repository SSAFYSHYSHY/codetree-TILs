#include <iostream>
#include <set>

using namespace std;

int n;
set<int> v;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		if (s == "add") {
			int a;
			cin >> a;

			v.insert(a);
		}
		else if (s == "remove") {
			int a;
			cin >> a;
			v.erase(a);
		}
		else if (s == "find") {
			int a;
			cin >> a;

			if (v.find(a) != v.end()) {
				cout << "true\n";
			}
			else {
				cout << "false\n";
			}
		}
		//set에서 a 보다 큰 최초의 숫자. 없다면 None;
		else if (s == "upper_bound") {
			int a;
			cin >> a;

			if (*v.upper_bound(a) > a) {
				cout << *v.upper_bound(a) << "\n";
			}
			else {
				cout << "None\n";
			}
		}
		//set에서 a 보다 같거나 작은 최초의 숫자. 없다면 None;

		else if (s == "lower_bound") {
			int a;
			cin >> a;

			if (*v.lower_bound(a) >= a) {
				cout << *v.lower_bound(a) << "\n";
			}
			else {
				cout << "None\n";
			}
		}

		//set에서 가장 큰 숫자를 출력. 비어있다면 None;
		else if (s == "largest") {
			if (!v.empty()) {
				cout << *v.rbegin() << "\n";
			}
			else {
				cout << "None\n";
			}
		}

		//set에서 가장 작은 숫자를 출력. 비어있다면 None;
		else if (s == "smallest") {
			if (!v.empty()) {
				cout << *v.begin() << "\n";
			}
			else {
				cout << "None\n";
			}
		}
	}
}