#include <iostream>
using namespace std;

int n;
int a[1005][5];
int dp[1005][5];

int main() {
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 3; j++)
            cin >> a[i][j];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= 3; j++) {
            for(int k = 1; k <= 3; k++) {
                if(j != k) {
                    dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + a[i + 1][k]);
                }
            }
        }
    }

    int ans = 0;
    for(int j = 1; j <= 3; j++) {
        ans = max(ans, dp[n][j]);
    }

    cout << ans;
    return 0;
}