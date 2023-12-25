#include <iostream>
#include <algorithm>

using namespace std;

int n, l;
int arr[1001];

int main() {
	cin >> n >> l;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		int lcnt = 0;

		for (int j = 0; j < n; j++) {
			if (arr[j] >= i) {
				cnt++;
			}
			else if (arr[j] == i - 1) {
				if (lcnt < l) {
					lcnt++;
					cnt++;
				}
			}
		}

		if (cnt >= i) {
			ans = i;
		}
	}

	cout << ans;
}