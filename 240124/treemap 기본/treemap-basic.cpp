#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<int> v1;
map<int, int> v;
int n;

int main() {
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
		else {
			map<int, int>::iterator it;

			for (it = v.begin(); it != v.end(); it++) {
				if (it->second != 0) {
					v1.push_back(it->second);
				}
			}

			if (v1.empty()) {
				cout << "None\n";
			}
			else {
				for (int i = 0; i < v1.size(); i++) {
					cout << v1[i] << " ";
				}
				cout << "\n";
			}

			v1.clear();
		}
	}
}