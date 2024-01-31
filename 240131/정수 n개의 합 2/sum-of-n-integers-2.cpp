#include <iostream>

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

	int ans = 0;
	for (int i = 0; i < n - k; i++) {
		int sum = 0;
		for (int j = i; j < i + k; j++) {
			sum += arr[j];
		}

		ans = max(ans, sum);
	}

	cout << ans;
}