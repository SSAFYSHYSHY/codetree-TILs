#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 1005;
int n;
int dp[MAXN][5][5];

int main() {
    cin >> n;

    dp[1][1][0] = 1;  // 첫 번째 날에 T를 받은 경우
    dp[1][0][1] = 1;  // 첫 번째 날에 B를 받은 경우
    dp[1][0][0] = 1;  // 첫 번째 날에 G를 받은 경우

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {
                dp[i + 1][j + 1][0] = (dp[i + 1][j + 1][0] + dp[i][j][k]) % MOD;
                dp[i + 1][j][0] = (dp[i + 1][j][0] + dp[i][j][k]) % MOD;
                dp[i + 1][j][k + 1] = (dp[i + 1][j][k + 1] + dp[i][j][k]) % MOD;
            }
        }
    }

    int ans = 0;
    for(int j = 0; j < 3; j++) {
        for(int k = 0; k < 3; k++) {
            ans = (ans + dp[n][j][k]) %MOD;
        }
    }

    cout << ans;
}