#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n, m;
string a, b;
int del[200001];
bool skip[200001];

bool Calc(int mid) {
	int idx = 0;

	for (int i = 1; i <= mid; i++) {
		skip[del[i] - 1] = true;
	}

	for (int i = 0; i <= n - 1; i++) {
		if (skip[i]) continue;

		if (idx < m && a[i] == b[idx]) idx++;
	}

	return idx == m;
}

int main() {
	cin >> a >> b;

	n = a.length();
	m = b.length();

	for (int i = 1; i <= n; i++) cin >> del[i];

	int l = 0, r = n, ans = -1;

	while (l <= r) {
		int mid = (l + r) / 2;

		if (Calc(mid)) {
			l = mid + 1;
			ans = max(ans, mid);
		}
		else {
			r = mid - 1;
		}

		for (int i = 1; i <= mid; i++) {
			skip[del[i] - 1] = false;
		}
	}

	cout << ans + 1;
}