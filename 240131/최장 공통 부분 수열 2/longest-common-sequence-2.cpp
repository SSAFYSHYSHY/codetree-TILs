#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    vector<vector<pair<int, int>>> path(n + 1, vector<pair<int, int>>(m + 1));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(dp[i][j] < dp[i - 1][j]) {
                dp[i][j] = dp[i - 1][j];
                path[i][j] = {i - 1, j};
            }

            if(dp[i][j] < dp[i][j - 1]) {
                dp[i][j] = dp[i][j - 1];
                path[i][j] = {i, j - 1};
            }

            if(a[i - 1] == b[j - 1] and dp[i][j] < dp[i - 1][j - 1] + 1) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                path[i][j] = {i - 1, j - 1};
            }
        }
    }

    vector<char> lcs;
    for(int i = n, j = m; i > 0 && j > 0;) {
        if(path[i][j] == make_pair(i - 1, j - 1) && a[i - 1] == b[j - 1]) {
            lcs.push_back(a[i - 1]);
            i--; j--;
        } else {
            tie(i, j) = path[i][j];
        }
    }

    for(auto it = lcs.rbegin(); it != lcs.rend(); ++it) {
        cout << it;
    }

    return 0;
}