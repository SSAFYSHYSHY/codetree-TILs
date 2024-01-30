#include <iostream>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int n = a.length(), m = b.length();
    int dp[1005][1005] = {0};
    
    for(int i = 1; i <= n; i++) dp[i][0] = i;
    for(int j = 1; j <= m; j++) dp[0][j] = j;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
    }

    // 결과를 출력합니다.
    cout << dp[n][m];

    return 0;
}