#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int n, m;

vector<pair<int, int>> segs;
vector<pair<int, int>> events;

int main() {
    cin >> n >> m;

    int x = 0;
    for (int i = 0; i < n; i++) {
        char ord;
        int len;
        cin >> len >> ord;

        if (ord == 'R') {
            segs.push_back({ x, x + len });
            x += len;
        }
        else if (ord == 'L') {
            segs.push_back({ x - len, x });
            x -= len;
        }
    }

    // 이벤트 추가
    for (int i = 0; i < n; i++) {
        int x1, x2;
        tie(x1, x2) = segs[i];

        events.push_back({ x1, +1 });
        events.push_back({ x2,-1 });
    }

    // 정렬
    sort(events.begin(), events.end());

    // 겹치는 길이 계산
    int sum = 0, ans = 0;
    for (int i = 0; i < 2 * n; i++) {
        int x, v;
        tie(x, v) = events[i];

        if (sum >= m) {
            int prev_x;
            tie(prev_x, ignore) = events[i - 1];
            ans += x - prev_x;
        }

        sum += v;
    }

    cout << ans;
}