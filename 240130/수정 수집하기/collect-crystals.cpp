#include <iostream>
using namespace std;

const int INF = 1987654321;
const int MAX_N = 1005;
const int MAX_K = 25;
const int STATES = 5;

int n, k;
string str;
int dp[MAX_N][MAX_K][STATES];

int main() {
    cin >> n >> k;
    cin >> str;
    str = " " + str;
    
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= k; j++) {
            dp[i][j][0] = dp[i][j][1] = -INF;
        }
    }
    
    dp[0][0][0] = 0;
    dp[0][1][1] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= k; j++) {
            if(dp[i][j][0] != -INF) {
                if(str[i + 1] == 'L') {
                    dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][0] + 1);
                    dp[i + 1][j + 1][1] = max(dp[i + 1][j + 1][1], dp[i][j][0]);
                } else {
                    dp[i + 1][j][0] = max(dp[i + 1][j][0], dp[i][j][0]);
                    dp[i + 1][j + 1][1] = max(dp[i + 1][j + 1][1], dp[i][j][0] + 1);
                }
            }

            if(dp[i][j][1] != -INF) {
                if(str[i + 1] == 'L') {
                    dp[i + 1][j + 1][0] = max(dp[i + 1][j + 1][0], dp[i][j][1] + 1);
                    dp[i + 1][j][1] = max(dp[i + 1][j][1], dp[i][j][1]);
                }
                else {
                    dp[i + 1][j + 1][0] = max(dp[i + 1][j + 1][0], dp[i][j][1]);
                    dp[i + 1][j][1] = max(dp[i + 1][j][1], dp[i][j][1] + 1);
                }
            }
        }
    }

    int ans = 0;
    for(int j = 0; j < k; j++) {
        ans = max(ans, dp[n][j][0]);
        ans = max(ans, dp[n][j][1]);
    }

    cout << ans;
    return 0;
}