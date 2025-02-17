#include <iostream>
#include <algorithm>

using namespace std;

long long n, m;
long long arr[100001];

bool Check(long long mid) {
    long long count = 0;

    for (int i = 0; i < m; i++) {
        count += mid / arr[i];
        if (count >= n) return true;
    }

    return count >= n;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + m);

    long long left = 1;  // 🔹 0이 아니라 1로 변경
    long long right = 1e18;  // 🔹 오버플로우 방지
    long long answer = right;

    while (left <= right) {
        long long mid = (left + right) / 2;

        if (Check(mid)) {
            answer = mid;
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    cout << answer;
}