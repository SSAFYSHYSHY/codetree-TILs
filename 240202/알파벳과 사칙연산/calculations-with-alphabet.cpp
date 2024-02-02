#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int n, ans = -21e8;
string s;
string alpha, oper;
vector<int> v;
unordered_map<char, int> key{
	{'a', 0},
	{'b', 1},
	{'c', 2},
	{'d', 3},
	{'e', 4},
	{'f', 5}
};


int Calc2() {

	string sum; 
	sum += to_string(v[key[alpha[0]]]);
	for (int i = 0; i < n ; i++) {
		sum = sum + oper[i] + to_string(v[key[alpha[i + 1]]]);
	}

	int num = (sum[0] - '0');
	for (int i = 2; i < sum.length(); i+=2) {
		if (sum[i-1] == '+') {
			num += (sum[i] - '0');
		}
		else if (sum[i-1] == '-') {
			num -= (sum[i] - '0');
		}
		else if (sum[i-1] == '*') {
			num *= (sum[i] - '0');
		}
	}

	return num;
}

void Calc(int now) {
	if (now == 6) {
		ans = max(ans, Calc2());
		return;
	}

	for (int i = 1; i <= 4; i++) {
		v.push_back(i);
		Calc(now + 1);
		v.pop_back();
	}
}

int main() {
	cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (isalpha(s[i])) {
			alpha += s[i];
		}
		else {
			n++;
			oper += s[i];
		}
	}

	Calc(0);

	cout << ans;
}