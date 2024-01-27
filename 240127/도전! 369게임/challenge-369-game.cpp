#include <iostream>
#include <string>
const int MOD = 1e9 + 7;

using namespace std;

string a;
long long arr[100005];
long long dp[100005][5];
long long ans;

bool flag;
int sm;

int main() {
	cin >> a;

	int len = a.length();

	arr[0] = 1;
	for (int i = 1; i <= len; i++) {
		arr[i] = arr[i - 1] * 10 % MOD;
	}

	for (int i = 0; i < len; i++) {
		int num = a[i] - '0';

		for (int x = 0; x < 10; x++) {
			if (x == 3 || x == 6 || x == 9) {
				ans += (dp[i][0] + dp[i][1] + dp[i][2]) * arr[len - i - 1] % MOD;
				ans %= MOD;
				continue;
			}

			for (int k = 0; k < 3; k++) {
				dp[i + 1][(x + k) % 3] += dp[i][k];
				dp[i + 1][(x + k) % 3] %= MOD;
			}
		}

		for (int x = 0; x < num; x++) {
			if (flag || x == 3 || x == 6 || x == 9) {
				ans += arr[len - i - 1];
				ans %= MOD;
			}
			else {
				dp[i + 1][(x + sm) % 3]++;
				dp[i + 1][(x + sm) % 3] %= MOD;
			}
		}

		if (num == 3 || num == 6 || num == 9) {
			flag = true;
		}
		else {
			sm += num;
		}
	}

	if (flag) {
		ans++;
		ans %= MOD;
	}
	else {
		dp[len][sm % 3]++;
		dp[len][sm % 3] %= MOD;
	}

	ans += dp[len][0];
	ans += (MOD - 1);
	ans %= MOD;

	cout << ans;
}