#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

#define INF 1987654321

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), b(m + 1);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    vector<vector<pair<int, int>>> path(n + 1, vector<pair<int, int>>(m + 1));
    vector<vector<int>> cur_best(n + 1, vector<int>(m + 1, INF));

    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    
    reverse(a.begin() + 1, a.end());
    reverse(b.begin() + 1, b.end());
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(dp[i - 1][j] > dp[i][j] || (dp[i - 1][j] == dp[i][j] && cur_best[i - 1][j] < cur_best[i][j])) {
                dp[i][j] = dp[i - 1][j];
                path[i][j] = {i - 1, j};
                cur_best[i][j] = cur_best[i - 1][j];
            }
            
            if(dp[i][j - 1] > dp[i][j] || (dp[i][j - 1] == dp[i][j] && cur_best[i][j - 1] < cur_best[i][j])) {
                dp[i][j] = dp[i][j - 1];
                path[i][j] = {i, j - 1};
                cur_best[i][j] = cur_best[i][j - 1];
            }

            if(a[i] == b[j] && (dp[i - 1][j - 1] + 1 > dp[i][j] || (dp[i - 1][j - 1] + 1 == dp[i][j] && a[i] < cur_best[i][j]))) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                path[i][j] = {i - 1, j - 1};
                cur_best[i][j] = a[i];
            }
        }
    }

    vector<int> lcs;
    for(int i = n, j = m; i > 0 && j > 0;) {
        if(path[i][j] == make_pair(i - 1, j - 1) && a[i] == b[j]) {
            lcs.push_back(a[i]);
            i--; j--;
        } else {
            tie(i, j) = path[i][j];
        }
    }

    for(int i = 0; i < lcs.size(); i++) {
        cout << lcs[i] << " ";
    }

    return 0;
}