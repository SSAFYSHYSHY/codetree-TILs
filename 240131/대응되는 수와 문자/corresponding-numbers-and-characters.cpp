#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int n, m;
string s[100001];
unordered_map<string, int> nodes;

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> s[i];

		nodes[s[i]] = i;
	}

	for (int i = 0; i < m; i++) {
		string key;
		cin >> key;

		if ('0' <= key[0] && key[0] <= '9') {
			cout << s[stoi(key)] << "\n";
		}
		else {
			cout << nodes[key] << "\n";
		}
	}
}