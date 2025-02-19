#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> meetings;

    // 회의 시작 시간과 종료 시간을 입력받아 vector에 저장
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        meetings.push_back({ e, s }); // 종료 시간을 기준으로 정렬할 것이므로, {종료시간, 시작시간} 순으로 저장
    }

    // 종료 시간이 빠른 순으로 정렬
    sort(meetings.begin(), meetings.end());

    int ans = 0; // 가능한 회의의 최대 개수
    int last_end = -1; // 마지막 회의의 종료 시간

    for (int i = 0; i < n; i++) {
        int start = meetings[i].second;
        int end = meetings[i].first;

        // 이전 회의의 종료 시간이 현재 회의의 시작 시간보다 작거나 같으면 회의 진행 가능
        if (last_end <= start) {
            ans++; // 회의 진행
            last_end = end; // 마지막 회의의 종료 시간을 갱신
        }
    }

    cout << n - ans << endl; // 취소해야 하는 회의의 최소 개수는 전체 회의 수에서 진행 가능한 회의 수를 뺀 값입니다.

    return 0;
}
