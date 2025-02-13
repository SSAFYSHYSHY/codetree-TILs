#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int R[100001];
string s;
int len;

int main() {
	cin >> s;

	len = s.length();

	//R 배열을 채워줌.
	R[len - 1] = 0;
	for (int i = len - 2; i >= 0; i--) {
		if (s[i] == ')' && s[i + 1] == ')') {
			R[i] = R[i + 1] + 1;
		}
		else {
			R[i] = R[i + 1];
		}
	}

	//
	long long ans = 0;
	for (int i = 0; i < len - 2; i++) {
		if (s[i] == '(' && s[i + 1] == '(') {
			ans += R[i + 2];
		}
	}

	cout << ans;
}