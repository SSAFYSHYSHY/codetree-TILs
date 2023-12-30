#include <iostream>

using namespace std;

int dp[21];
int n;

int main() {
	cin >> n;

	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= 19; i++) {
		int sum = 0;
		for (int j = 0; j < i; j++) {
			sum += dp[j] * dp[i - j - 1];
		}
		dp[i] = sum;
	}

	cout << dp[n];

}