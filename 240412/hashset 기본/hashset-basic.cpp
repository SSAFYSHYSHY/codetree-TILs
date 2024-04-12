#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> v;
int n;

int main() {
	cin >> n;

	while (n--) {
		string a;
		cin >> a;

		if (a == "find") {
			int b;
			cin >> b;

			if (v.find(b) != v.end()) {
				cout << "true\n";
			}
			else {
				cout << "false\n";
			}
		}
		else if (a == "add") {
			int b;
			cin >> b;

			v.insert(b);

		}
		else if (a == "remove") {
			int b;
			cin >> b;

			v.erase(b);

		}
	}

}