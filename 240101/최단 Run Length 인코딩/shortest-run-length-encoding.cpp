#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s, s1;
int ans = 21e8;

string Calc(string s) {
	int cnt = 1;
	string s1;

	s1 += s[0];

	for (int i = 0; i < s.length(); i++) {
		if (s[i] != s[i + 1]) {
			s1 += to_string(cnt);
			s1 += s[i + 1];
			cnt = 1;
		}
		else {
			cnt++;
		}
	}

	return s1;
}

int main() {
	cin >> s;

	//길이 만큼 완탐.
	for (int t = 0; t < s.length(); t++) {

		// 0번 부터 s를 다시 정렬.
		char temp = s[s.length() - 1];

		for (int i = s.length() - 1; i > 0; i--) {
			s[i] = s[i - 1];
		}
		s[0] = temp;

		//순환하는 함수.
		string s1 = Calc(s);
		int len = s1.length();
		len -= 1;

		//cout << s1 << "\n";

		ans = min(ans, len);
	}

	cout << ans;
}