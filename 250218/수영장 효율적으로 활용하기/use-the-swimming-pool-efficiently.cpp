#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, l, r;  // n: 사람 수, m: 레인 수
vector<int> times;  // 각 사람의 수영 시간

// 주어진 maxTime에 대해 레인을 배정할 수 있는지 체크하는 함수
bool canAssignLeans(int maxTime) {
    int currentSum = 0;  // 현재 레인의 수영시간 합
    int requiredLanes = 1;  // 필요한 레인 수 (최소 1개 레인은 필요)

    for (int i = 0; i < n; i++) {
        if (currentSum + times[i] > maxTime) {
            requiredLanes++;  // 새 레인을 사용
            currentSum = times[i];  // 새 레인의 첫 사람은 현재 사람
            if (requiredLanes > m) {  // 레인 수가 m을 초과하면 불가능
                return false;
            }
        }
        else {
            currentSum += times[i];  // 현재 레인에 수영시간 더함
        }
    }

    return true;
}

int main() {
    cin >> n >> m;
    times.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> times[i];

        l = max(l, times[i]);
        r += times[i];

    }

    int answer = r;

    while (l <= r) {
        int mid = (l + r) / 2;

        if (canAssignLeans(mid)) {
            answer = mid;
            r = mid - 1;  // 최적값을 찾기 위해 탐색 범위 좁힘
        }
        else {
            l = mid + 1;  // 불가능한 경우 더 큰 값을 찾음
        }
    }

    cout << answer << endl;
    return 0;
}