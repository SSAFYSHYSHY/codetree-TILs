#include <iostream>
#include <algorithm>
#include <climits>
#define MAX_NUM 10000000000

using namespace std;

long long n, m;
long long arr[1000001];

bool Calc(long long mid) {
    long long count = 0;

    for (long long i = 0; i < m; i++) {
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
    sort(arr, arr + m); // m개만 정렬해야 함

    long long left = 1;
    long long right = MAX_NUM;
    long long max_num = MAX_NUM; // 최소값을 찾아야 하므로 -1로 설정
    long long ans = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;

        if (Calc(mid)) {
            right = mid - 1;
            ans = mid;
        }
        else {
            left = mid + 1;
        }
    }

    cout << ans;
}
