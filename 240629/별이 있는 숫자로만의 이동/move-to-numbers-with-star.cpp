#include <iostream>

using namespace std;

int n, k;
int arr[501][501];
int prefix[501][501];
int ans = 0;

int main(){
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			prefix[i][j] = prefix[i][j - 1] + arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int sum = 0;

			for (int r = i - k; r <= i + k; r++) {
				int c = k - abs(i - r);

				if (1 <= r && r <= n) {
					sum += prefix[r][min(j + c, n)] - prefix[r][max(j - c - 1, 0)];
				}
			}

			ans = max(ans, sum);
		}
	}

	cout << ans;
}