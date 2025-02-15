#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001]; // 수열 저장
int n, k;

void Input() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

int main() {
    Input();

    int j = 0, cnt = 0, ans = 1e9; // 1의 개수 cnt, 최솟값 ans
    for (int i = 0; i < n; i++) {
        // j를 이동시키며 1의 개수가 K개 이상이 되도록 함
        while (j < n && cnt < k) {
            if (arr[j] == 1) cnt++;
            j++;
        }

        // 1이 K개 이상 포함된 구간이라면 최솟값 업데이트
        if (cnt >= k) ans = min(ans, j - i);

        // i가 한 칸 이동하므로, 기존 값이 1이면 cnt 감소
        if (arr[i] == 1) cnt--;
    }

    if (ans == 1e9) cout << -1;
    else cout << ans;

    return 0;
}
