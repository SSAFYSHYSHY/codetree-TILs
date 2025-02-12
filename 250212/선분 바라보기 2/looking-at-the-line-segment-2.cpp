#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>

using namespace std;

struct Pair {
    int a, b, y, idx;
    
    bool operator<(const Pair& p) const {
        return a < p.a;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<Pair> pairs;
    vector<bool> checked(N, false);
    map<int, int> tMap;  // y 좌표를 key로 사용하여 선분 관리

    for (int i = 0; i < N; i++) {
        int y, x1, x2;
        cin >> y >> x1 >> x2;

        pairs.push_back({x1, y, 1, i});  // 시작점
        pairs.push_back({x2, y, -1, i}); // 끝점
    }

    // 정렬 (x 좌표 기준)
    sort(pairs.begin(), pairs.end());

    for (int i = 0; i < 2 * N; i++) {
        int xDot = pairs[i].a;
        int yDot = pairs[i].b;
        int loc = pairs[i].y;
        int idx = pairs[i].idx;

        if (loc == 1) { // 선분 시작
            if (tMap.empty() || tMap.begin()->first > yDot) {
                checked[idx] = true;
            }
            tMap[yDot] = idx;
        } else { // 선분 종료
            tMap.erase(yDot);

            if (!tMap.empty()) {
                int firstIdx = tMap.begin()->second;
                if (!checked[firstIdx]) {
                    checked[firstIdx] = true;
                }
            } else {
                if (!checked[idx]) {
                    checked[idx] = true;
                }
            }
        }
    }

    // True로 체크된 선분 개수 세기
    int count = 0;
    for (bool isChecked : checked) {
        if (isChecked) count++;
    }

    cout << count << '\n';
    return 0;
}