#include <iostream>
using namespace std;

int n;
int a[1005][5];
int dp[1005][5][5];

int main() {
    cin >> n;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 3; j++)
            cin >> a[i][j];
    }

    for(int j = 1; j <= 3; j++) {
        dp[1][j][j] = a[1][j];
    }

    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= 3; j++) {
            for(int k = 1; k <= 3; k++) {
                for(int l = 1; l <= 3; l++) {
                    if(k != l) {
                        dp[i + 1][j][l] = max(dp[i + 1][j][l], dp[i][j][k] + a[i + 1][l]);
                    }
                }
            }
        }
    }

    int ans = 0;
    for(int j = 1; j <= 3; j++) {
        for(int k = 1; k <= 3; k++) {
            if(j != k) {
                ans = max(ans, dp[n][j][k]);
            }
        }
    }

    cout << ans;
    return 0;
}