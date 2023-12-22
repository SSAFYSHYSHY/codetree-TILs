#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> stones(n);
    for (int i = 0; i < n; ++i) {
        cin >> stones[i];
    }

    int minMaxValue = 21e8;

    for (int start = 0; start < k; ++start) {
        vector<int> visited(n, 0);
        int currentPos = start;
        int maxVal = 0;

        while (currentPos < n) {
            visited[currentPos] = 1;
            maxVal = max(maxVal, stones[currentPos]);
            currentPos += k;
        }

        if (currentPos - k < n) {
            maxVal = max(maxVal, *max_element(stones.begin() + currentPos - k + 1, stones.end()));
        }

        minMaxValue = min(minMaxValue, maxVal);
    }

    cout << minMaxValue << endl;

    return 0;
}