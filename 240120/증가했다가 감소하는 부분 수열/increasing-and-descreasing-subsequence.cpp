#include <iostream>

using namespace std;

int arr[1001];
int n, idx;
int s_dp[1001] = {0,};
int b_dp[1001] = {0,};

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		s_dp[i] = 1;
		b_dp[i] = 1;
	}

	//작은 것부터 큰것까지.
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				s_dp[i] = max(s_dp[i], s_dp[j] + 1);
			}
		}
	}

	//큰 인덱스부터 작은 것까지.
	for (int i = n - 2; i >= 0; i--) {
		for (int j = n - 1; j > i; j--) {

			if (arr[j] < arr[i]) {
				b_dp[i] = max(b_dp[i], b_dp[j] + 1);
			}
		}
	}

	int ans = 0;
	//1 이상 끼리의 것들을 합함.
	for (int i = 0; i < n; i++) {
		if (b_dp[i] > 1 && s_dp[i] > 1) {
			ans = max(ans, b_dp[i] + s_dp[i]);
		}
	}
	ans -= 1;

	//만약 크고 작은 것에서 최대값을 찾게되면.
	for (int i = 0; i < n; i++) {
		ans = max(ans, s_dp[i]);
		ans = max(ans, b_dp[i]);
	}
	cout << ans;
}