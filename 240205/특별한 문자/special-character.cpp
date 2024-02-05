#include <string>
#include <unordered_map>
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

string s;
unordered_map<char, int> v;

int main() {
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		v[s[i]]++;
	}

	char c;
	bool flag = false;
	for (int i = 0; i < s.length(); i++) {
		if (v[s[i]] == 1 && !flag) {
			c = s[i];
			flag = true;
			break;
		}
	}

	if (flag == true) {
		cout << c;
	}
	else {
		cout << "None";
	}
}