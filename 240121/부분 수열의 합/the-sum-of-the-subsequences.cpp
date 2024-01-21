#include <iostream>

using namespace std;

int n, m;
int arr[101];
bool dp[10001] = {false,};

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = true;

	for(int i = 0; i < n ; i++) {
		for (int j = m; j >= arr[i]; j--) {
			if (arr[i] <= j && dp[j - arr[i]]) {
				dp[j] = true;
			}
		}
	}

	if (dp[m]) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}

	return 0;
}