#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_LENGTH = 100000;
const int NUM_SELECT = 3;
vector<int> arr(MAX_LENGTH + 1);
vector<vector<int>> DP(NUM_SELECT + 2, vector<int>(MAX_LENGTH + 1));

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    DP[1][1] = arr[1];

    for (int i = 1; i <= NUM_SELECT; i++) {
        for (int j = 2 * i - 1; j <= n; j++) {
            if (j < 2) {
                DP[i][j] = arr[j];
                continue;
            }
            DP[i][j] = max(DP[i][j - 1], DP[i - 1][j - 2] + arr[j]);
        }
    }

    cout << DP[NUM_SELECT][n] << "\n";
    return 0;
}