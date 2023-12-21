#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int T, a, b;
int s[101];
int n[101];
int cnt_s, cnt_n;

int main() {
	cin >> T >> a >> b;

	for (int i = 0; i < T; i++) {
		char a;
		int b;
		cin >> a >> b;

		if (a == 'S') {
			s[cnt_s++] = b;
		}
		else {
			n[cnt_n++] = b;
		}
	}

	int ans = 0;
	for (int i = a; i <= b; i++) {
		int dist_s = 21e8;
		int dist_n = 21e8;

		for (int j = 0; j < cnt_s; j++) {
			dist_s = min(dist_s, abs(s[j] - i));
		}
		for (int j = 0; j < cnt_n; j++) {
			dist_n = min(dist_n, abs(n[j] - i));
		}

		if (dist_s <= dist_n) {
			ans++;
		}
	}

	cout << ans;
}