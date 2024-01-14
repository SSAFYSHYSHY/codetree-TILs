#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

string s;
int n, ans = INT_MIN;
int arr[201];

int Calc3(int idx) {
	return arr[s[idx] - 'a'];
}

int Calc2() {
	int ans = Calc3(0);

	for (int i = 2; i <= n; i += 2) {
		if (s[i - 1] == '+') ans += Calc3(i);
		else if (s[i - 1] == '-') ans -= Calc3(i);
		else {
			ans *= Calc3(i);
		}
	}

	return ans;
}

void Calc(int num) {
	if (num == n) {
		ans = max(ans, Calc2());
		return;
	}

	for (int i = 1; i <= 4; i++) {
		arr[num] = i;
		Calc(num + 1);
	}
}

int main() {
	cin >> s;

	n = s.length();

	Calc(0);

	cout << ans;
}