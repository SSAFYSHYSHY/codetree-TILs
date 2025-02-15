#include <iostream>
#include <algorithm>

using namespace std;

long long n, m;
long long arr[100002];   // 특정 위치 배열
long long office[100002]; // 사무실 위치 배열
long long ans = 0;

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> office[i];
    }

    sort(arr, arr + n);
    sort(office, office + m); // 정렬된 arr와 office 배열을 활용

    int j = 0;
    for (int i = 0; i < n; i++) {
        // arr[i]에 대해 가장 가까운 사무실을 찾는다.
        while (j + 1 < m && abs(office[j + 1] - arr[i]) <= abs(office[j] - arr[i])) {
            j++;
        }
        ans = max(ans, abs(office[j] - arr[i]));
    }

    cout << ans;
    return 0;
}