#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, ans;
int dp[1001];
pair<int, int> arr[1001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
        dp[i] = 1;
	}

	sort(arr, arr + n);
	
    for(int i = 0; i < n ;i++) {
        dp[i] = 1;

        for(int j = 0; j < i ; j++) {
            int x1;
            tie(x1, ignore) = arr[i];

            int x2;
            tie(ignore, x2) = arr[j];

            if(x2 < x1) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans;

}