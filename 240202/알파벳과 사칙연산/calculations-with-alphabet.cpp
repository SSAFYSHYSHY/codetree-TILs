#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int n, ans = -21e8;
string s;
string alpha, oper;
vector<int> v;
int num[7];

int Conv(int idx) {
	return num[s[idx] - 'a'];
}

int Calc2() {
	int len = (int)s.size();
	int value = Conv(0);

	for (int i = 2; i < len; i+=2) {
		if (s[i-1] == '+') {
			value += Conv(i);
		}
		else if (s[i-1] == '-') {
			value -= Conv(i);
		}
		else if (s[i-1] == '*') {
			value *= Conv(i);
		}
	}

	return value;
}

void Calc(int now) {
	if (now == 6) {
		ans = max(ans, Calc2());
		return;
	}

	for (int i = 1; i <= 4; i++) {
		num[now] = i;
		Calc(now + 1);
	}
}

int main() {
	cin >> s;

	Calc(0);

	cout << ans;
}