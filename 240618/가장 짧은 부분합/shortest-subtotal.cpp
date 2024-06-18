#include <iostream>

using namespace std;

int arr[100001];
int n,s;

int ans = 21e8;

int main() {
	cin >> n >> s;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int j = 0, sum = 0;
	for (int i = 1; i <= n; i++) {

		while (j + 1 <= n && sum < s) {
			sum += arr[j + 1];
			j++;

		}

		if (sum < s) {
			break;
		}

		ans = min(ans, j - i + 1);
		sum -= arr[i];
	}

	if (ans == 21e8) {
		cout << -1;
	}
	else {
		cout << ans;
	}
}