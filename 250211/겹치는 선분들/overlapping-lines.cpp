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

    int x1 = 0, x2 = 0;
    for (int i = 0; i < n; i++) {
        char ord;
        int len;
        cin >> len >> ord;

        if (ord == 'R') {
            x2 = x1 + len;
        }
        else if (ord == 'L') {
            x2 = x1 - len;
        }

        segs.push_back({ x1, x2 });
        x1 = x2;
    }

    // 이벤트 추가
    for (auto& seg : segs) {
        int a = seg.first, b = seg.second;
        if (a > b) swap(a, b);  // 순서 보정

        events.push_back({ a, +1 });
        events.push_back({ b, -1 });
    }

    // 정렬
    sort(events.begin(), events.end());

    // 겹치는 길이 계산
    int sum = 0, prevX = events[0].first, result = 0;
    for (auto& e : events) {
        int x = e.first, v = e.second;

        if (sum == m) {
            result += (x - prevX);  // 구간 길이 누적
        }

        sum += v;
        prevX = x;
    }

    cout << result + 1<< '\n';
}