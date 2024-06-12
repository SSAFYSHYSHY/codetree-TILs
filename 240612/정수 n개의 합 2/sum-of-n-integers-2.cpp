#include <iostream>

using namespace std;

int arr[100001];
int prefix[100001];
int n, k, ans = 0;

int Get(int s, int e) {
	return prefix[e] - prefix[s - 1];
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	prefix[0] = arr[0];
	for (int i = 1; i < n; i++) {
		prefix[i] = prefix[i - 1] + arr[i];
	}

	for (int i = 0; i < n - k + 1; i++) {
		ans = max(ans, Get(i, i + k - 1));
	}

	cout << ans;
}