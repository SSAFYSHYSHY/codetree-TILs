#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[101];

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int ans = 10000;
	for (int i = 1; i <= 10000; i++) {
		bool flag = true;
		int cnt = 0 ,sect = 1;

		for (int j = 0; j < n; j++) {
			if (arr[j] > i) {
				flag = false;
				break;
			}

			if (cnt + arr[j] > i) {
				cnt = 0;
				sect += 1;
			}

			cnt += arr[j];
		}

		if (flag && sect <= m) {
			ans = min(ans, i);
		}
	}

	cout << ans;
}