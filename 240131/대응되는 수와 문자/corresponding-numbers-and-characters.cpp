#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int n, m;
unordered_map<int, string> nodes;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		nodes[i] = s;
	}

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;

		if ("0" <= s && s <= "9") {
			int num = stoi(s);

			cout << nodes[num-1] << "\n";
		}
		else {
			for (int j = 0; j < n; j++) {
				if (nodes[j] == s) {
					cout << j+1 << "\n";
				}
			}
		}
	}
}