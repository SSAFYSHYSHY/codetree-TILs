#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int arr[100001];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> freq; // 각 숫자의 등장 횟수 저장
    int j = 0, ans = 0;

    for (int i = 0; i < n; i++) {
        while (j < n && freq[arr[j]] < k) {
            freq[arr[j]]++;
            j++;
        }

        ans = max(ans, j - i);  // 최장 길이 갱신

        freq[arr[i]]--;  // i를 증가시키며 현재 범위에서 제외
    }

    cout << ans << endl;
    return 0;
}