#include <iostream>
#include <climits>

using namespace std;

int arr[100001];
int dp[100001];
int n;

void Initial() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		dp[i] = INT_MIN;
	}

	dp[1] = arr[1];
}

int main() {
	Initial();

	for (int i = 2; i <= n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
	}
	int ans = INT_MIN;

	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans;

}