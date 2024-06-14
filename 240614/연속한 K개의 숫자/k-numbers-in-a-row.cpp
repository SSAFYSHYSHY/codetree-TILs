#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];
int prefix[100001];

int n, k, b, ans = 21e8;

int Sum(int s, int e) {
	return prefix[e] - prefix[s-1];
}

int main() {
	cin >> n >> k >> b;

	while (b--) {
		int x;
		cin >> x;

		arr[x] = 1;
	}

	prefix[0] = 0;
	for (int i = 1; i <= n; i++) {
		prefix[i] = prefix[i - 1] + arr[i];
	}

	for (int i = 1; i <= n - k + 1; i++) {
		ans = min(ans, Sum(i, i + k - 1));
	}
	cout << ans;
}