#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> v;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		if (s == "add") {
			int a, b;
			cin >> a >> b;
			v[a] = b;
		}
		else if (s == "find") {
			int a;
			cin >> a;

			if (!v[a]) {
				cout << "None\n";
			}
			else {
				cout << v[a] << "\n";
			}
		}
		else if (s == "remove") {
			int a;
			cin >> a;

			v.erase(a);
		}

	}
}