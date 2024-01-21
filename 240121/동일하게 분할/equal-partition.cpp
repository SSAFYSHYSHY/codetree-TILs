#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>

using namespace std;

int n, m;
int arr[101];
bool dp[101][1001];

void Initial() {
	dp[0][0] = true;
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		m += arr[i];
	}

	Initial();

	for (int i = 1; i <= n; i++) {
		//Case1 i 번수를 선택해서 합이 j가 된 경우.

		//Case2 i 번수를 선택하지 않고 합 이 j가 된경우.

		for (int j = 0; j <= m; j++) {
			//case1

			if (j >= arr[i] && dp[i - 1][j - arr[i]])
				dp[i][j] = true;

			if (dp[i - 1][j]) {
				dp[i][j] = true;
			}
		}

	}

	int a = 0 , b = 0;
	for (int i = 1; i < m; i++) {
		if (dp[n][i]) {
			a = i;
			b = abs(m - i);

			if (a == b) {
				cout << "Yes";
				return 0;
			}
		}
	}

	cout << "No";

}