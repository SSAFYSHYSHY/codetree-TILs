#include <iostream>
#include <string>

using namespace std;

int x, y;
string s;

bool Calc(string s) {
	for (int j = 0; j < s.length(); j++) {
		if (s[j] != s[s.length() - j - 1]) {
			return false;
		}
	}

	return true;
}

int main() {
	cin >> x >> y;

	int cnt = 0;
	for (int i = x; i <= y; i++) {
		s = to_string(i);
		if (Calc(s)) {
			cnt++;
		}
	}

	cout << cnt;
}