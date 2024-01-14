#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


char crr[201];
char new_crr[201];
string s;
int cnt = 0, ans = 0, idx = 0;
vector<int> v;

void Initial() {
	for (int i = 0; i < idx; i++) {
		new_crr[i] = crr[i];
	}
}

int Calc2() {
	int sum = v[0];

	Initial();

	int num = 0;
	for (int i = 1; i < v.size(); i++) {
		if (new_crr[num] == '+') {
			sum += v[i];
		}
		else if (new_crr[num] == '-') {
			sum -= v[i];
		}
		else if (new_crr[num] == '*') {
			sum *= v[i];
		}
		num++;
	}

	return sum;
}

void Calc(int num) {
	if (num == cnt) {
		ans = max(ans, Calc2());
		return;
	}

	for (int i = 1; i <= 4; i++) {
		v.push_back(i);
		Calc(num + 1);
		v.pop_back();
	}
}

int main() {
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if ('a' <= s[i] && s[i] <= 'z') {
			cnt++;
		}
		else {
			crr[idx] = s[i];
			idx++;
		}
	}

	Calc(0);

	cout << ans;
}