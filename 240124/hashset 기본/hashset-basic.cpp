#include <iostream>
#include <unordered_set>

using namespace std;

int n;
unordered_set<int> v;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		if (s == "find") {
			int a;
			cin >> a;

			if (v.find(a) == v.end()) {
				cout << "false\n";
			}
			else {
				cout << "true\n";
			}
		}
		else if (s == "add") {
			int a;
			cin >> a;
			v.insert(a);
		}
		else {
			int a;
			cin >> a;
			v.erase(a);
		}
	}
}