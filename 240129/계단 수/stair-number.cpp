#include <iostream>
using namespace std;

int n;
int dp[1005][15];

#define MOD 1000000007

int main() {
    cin >> n;
    
    for(int i = 1; i <= 9; i++) dp[1][i] = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= 9; j++) {
            if(j > 0) {
                dp[i + 1][j - 1] = (dp[i + 1][j - 1] + dp[i][j]) % MOD;
            }

            if(j < 9) {
                dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % MOD;
            }
        }
    }

    int ans = 0;
    for(int j = 0; j <= 9; j++) {
        ans = (ans + dp[n][j]) % MOD;
    }

    cout << ans;
    return 0;
}