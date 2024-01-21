#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int n, m = 0;
int arr[101];
int dp[10001];

void Initial() {

	dp[0] = 0;
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	Initial();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i] = max(dp[i], dp[i - j] + arr[j]);
		}
	}

	cout << dp[n];

}