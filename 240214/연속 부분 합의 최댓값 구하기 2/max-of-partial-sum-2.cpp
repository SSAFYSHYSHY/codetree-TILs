#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int maxSum = arr[0]; // 최대 연속 부분합
    int currentSum = arr[0]; // 현재까지의 부분합

    // 배열을 순회하면서 최대 연속 부분합을 찾음
    for (int i = 1; i < n; ++i) {
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSum = max(maxSum, currentSum);
    }

    cout << maxSum << endl;

    return 0;
}