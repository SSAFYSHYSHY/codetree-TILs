#include <iostream>

using namespace std;

int arr[1001];
int prefix[1001];
int n, k, cnt = 0, ans = 0;

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

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < n - i + 1; j++) {
			ans = Get(j, j + i - 1);

			if (ans == k) {
				cnt++;
			}
		}
	}

	cout << cnt;
}