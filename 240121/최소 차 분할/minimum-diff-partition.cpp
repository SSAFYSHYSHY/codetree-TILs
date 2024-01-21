#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int nums[n];
    int s = 0;

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
        s += nums[i];
    }

    bool dp[s + 1] = {false};
    dp[nums[0]] = true;

    for (int i = 1; i < n; ++i) {
        int num = nums[i];
        int arr_nums[s + 1];

        for (int & arr_num : arr_nums) {
            arr_num = 0;
        }

        for (int j = 0; j <= s; ++j) {
            if (dp[j]) {
                dp[j] = false;
                arr_nums[abs(j - num)] = 1;
                arr_nums[j + num] = 1;
            }
        }

        for (int j = 0; j <= s; ++j) {
            if (arr_nums[j] == 1) {
                dp[j] = true;
            }
        }
    }

    int ans = 0;

    for (int i = 0; i <= s; ++i) {
        if (dp[i]) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}