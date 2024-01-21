#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[3] = {1,2,5};
int dp[1001];

void Initial() {

	dp[0] = 1;
}

int main() {
	cin >> n;

	Initial();

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			if (i >= arr[j]) {
				dp[i] = (dp[i] + dp[i - arr[j]]) % 10007;
 			}
		}
	}

	int ans = dp[n];


	cout << ans;
}