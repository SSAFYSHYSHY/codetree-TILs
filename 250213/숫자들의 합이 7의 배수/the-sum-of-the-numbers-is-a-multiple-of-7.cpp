#include <iostream>
#include <unordered_map>

using namespace std;

long long n;
long long arr[50001];  // 최대 50000개
unordered_map<long long, long long> mod_idx; // 나머지 값 -> 최초 등장 인덱스 저장

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (long long i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    long long prefix_sum = 0;
    long long max_len = 0;
    mod_idx[0] = 0; // 누적합이 0일 경우 대비

    for (long long i = 1; i <= n; i++) {
        prefix_sum += arr[i];
        long long mod_val = prefix_sum % 7;

        // 나머지 값이 처음 등장하면 저장
        if (mod_idx.find(mod_val) == mod_idx.end()) {
            mod_idx[mod_val] = i;
        }
        else {
            // 같은 나머지가 이전에 등장했으면 길이 계산
            max_len = max(max_len, i - mod_idx[mod_val]);
        }
    }

    cout << max_len << '\n';
    return 0;
}
