#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

int n, ans = INT_MAX;
int arr[11];


void Calc(int now, int cnt) {
	if (now == n - 1) {
		ans = min(ans, cnt);
		return;
	}

	for (int i = 1; i <= arr[now]; i++) {
		Calc(now + i, cnt + 1);
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	Calc(0,0);

	if (ans == INT_MAX) {
		cout << -1;
	}
	else {
		cout << ans;
	}
}