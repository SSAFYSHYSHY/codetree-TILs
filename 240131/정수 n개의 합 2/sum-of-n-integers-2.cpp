#include <iostream>
#include <climits>

using namespace std;

int n;
int arr[100001];
int pre_sum[100001];
int k;

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		pre_sum[i + 1] = pre_sum[i] + arr[i];
	}

	int ans = INT_MIN;
	for (int i = k; i <= n; i++) {
		int sum = pre_sum[i] - pre_sum[i - k];
		ans = max(ans, sum);
	}
	cout << ans;

}