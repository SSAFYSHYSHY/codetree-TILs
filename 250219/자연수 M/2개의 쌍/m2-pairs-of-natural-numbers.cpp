#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minMaxPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());  // 정렬
    int m = nums.size();
    int minC = 0;

    for (int i = 0; i < m / 2; i++) {
        int sum = nums[i] + nums[m - 1 - i];  // 가장 작은 값 + 가장 큰 값
        minC = max(minC, sum);  // 최댓값을 최소화
    }

    return minC;
}

int main() {
    int m;
    cin >> m;
    
    vector<int> nums(m);
    for (int i = 0; i < m; i++) {
        cin >> nums[i];
    }

    cout << minMaxPairSum(nums) + 1<< endl;
    return 0;
}
