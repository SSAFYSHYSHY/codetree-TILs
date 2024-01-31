#include <iostream>
#include <climits>
#include <algorithm>

#define MAX_N 500
#define MAX_M 100
#define MAX_K 4

using namespace std;

int dp[MAX_N + 1][MAX_M + 1][MAX_K + 1];

int n, m;

int a[MAX_N + 1];

void Initialize() {
    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= m; j++)
            for(int k = 1; k <= MAX_K; k++)
                dp[i][j][k] = INT_MIN;
    
    for(int k = 1; k <= MAX_K; k++)
        dp[1][0][k] = (a[1] == k);
}

int main() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    Initialize();

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            for(int k = 1; k <= MAX_K; k++) {
                for(int l = 1; l <= MAX_K; l++) {
                    
                    if(l == k)
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][l] + (a[i] == k));
                    
                    if(l != k && j > 0)
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][l] + (a[i] == k));
                }
            }
        }
    }

    int ans = 0;

    for(int j = 0; j <= m; j++)
        for(int k = 1; k < MAX_K; k++)
            ans = max(ans, dp[n][j][k]);

    cout << ans;
}