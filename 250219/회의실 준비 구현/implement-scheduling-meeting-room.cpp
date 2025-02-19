#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> v;

// 끝나는 시간을 기준으로 오름차순 정렬
bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        v.push_back({ s, e });
    }

    // 끝나는 시간을 기준으로 오름차순 정렬
    sort(v.begin(), v.end(), cmp);

    int ans = 0;  // 선택된 회의 개수
    int last_end_time = 0;  // 마지막으로 선택된 회의의 끝나는 시간

    for (int i = 0; i < v.size(); i++) {
        int s = v[i].first;
        int e = v[i].second;

        // 현재 회의의 시작 시간이 마지막 선택한 회의의 끝나는 시간 이후라면 선택
        if (s >= last_end_time) {
            ans++;
            last_end_time = e;  // 마지막 회의의 끝나는 시간 업데이트
        }
    }

    cout << ans;
}
