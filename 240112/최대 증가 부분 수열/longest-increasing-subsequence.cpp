#include <iostream>
#include <vector>

using namespace std;

int main() {
    int num;
    cin >> num;

    vector<int> a(num + 1);
    vector<int> dp(num + 1, 0);

    for (int i = 1; i <= num; ++i) {
        cin >> a[i];
    }

    dp[1] = 1;

    for (int i = 2; i <= num; ++i) {
        for (int j = 1; j < i; ++j) {
            if (a[j] < a[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= num; ++i) {
        result = max(result, dp[i]);
    }

    cout << result << endl;

    return 0;
}