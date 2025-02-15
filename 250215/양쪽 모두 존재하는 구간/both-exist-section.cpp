#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int n, m;
vector<int> arr;
unordered_map<int, int> inside, outside;

bool valid() {
    if (inside.size() < m) return false; // 구간 안에 1~M이 하나씩 존재해야 함.

    for (int num = 1; num <= m; num++) {
        if (outside[num] > 0) return true; // 구간 밖에도 1~M 중 하나가 존재해야 함.
    }
    return false;
}

int main() {
    cin >> n >> m;
    arr.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (1 <= arr[i] && arr[i] <= m) {
            outside[arr[i]]++; // 초기에 모든 숫자는 구간 밖에 존재
        }
    }

    int j = 0, ans = n + 1; // 최소 길이를 찾으므로 ans를 충분히 큰 값으로 설정

    for (int i = 0; i < n; i++) {
        while (j < n && !valid()) {
            if (1 <= arr[j] && arr[j] <= m) {
                inside[arr[j]]++; // 구간 안으로 이동
                outside[arr[j]]--; // 구간 밖에서 제거
                if (outside[arr[j]] == 0) outside.erase(arr[j]);
            }
            j++;
        }

        if (valid()) ans = min(ans, j - i); // 조건 만족 시 최솟값 갱신

        // i가 증가하면 현재 요소를 구간에서 제거
        if (1 <= arr[i] && arr[i] <= m) {
            inside[arr[i]]--;
            if (inside[arr[i]] == 0) inside.erase(arr[i]);
            outside[arr[i]]++; // 제거된 숫자는 다시 구간 밖으로
        }
    }

    cout << (ans == n + 1 ? -1 : ans) << endl; // 답이 갱신되지 않았으면 -1 출력
    return 0;
}
