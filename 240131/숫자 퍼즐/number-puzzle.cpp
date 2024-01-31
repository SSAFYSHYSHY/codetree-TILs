#include <iostream>
using namespace std;

#define INF 1987654321

int n, m, k;
int dp[15][205][205];

int main() {
    cin >> n >> m >> k;

    for(int i = 1; i <= m; i++) dp[1][i][i] = 1;
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = 1; k <= m; k++) {
                for(int l = 1; l <= k; l++) {
                    if(j + l > m) break;
                    dp[i + 1][j + l][l] += dp[i][j][k];
                    dp[i + 1][j + l][l] = min(dp[i + 1][j + l][l], (int)1e9);
                }
            }
        }
    }

    int cur_l = 1;
    int cur_m = m;
    for(int i = n; i >= 1; i--) {
        while(dp[i][cur_m][cur_l] < k) {
            k -= dp[i][cur_m][cur_l];
            cur_l++;
        }

        cout << cur_l << " ";
        cur_m = cur_l;
    }

    return 0;
}