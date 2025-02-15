#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

struct Point {
    int x, y;

    bool operator<(const Point& p) const {
        if (y == p.y) return x < p.x;
        return y < p.y;
    }
};

const int MAX_LENGTH = 100000;
const int MAX_INT = 1000000;
vector<vector<Point>> pointList(MAX_INT + 1);
set<Point> pointSet;
set<int> xSet;
vector<int> xList;

void addPoint(int idx) {
    for (const auto& p : pointList[idx]) {
        pointSet.insert(p);
    }
}

void removePoint(int idx) {
    for (const auto& p : pointList[idx]) {
        pointSet.erase(p);
    }
}

bool satisfied(int D) {
    if (pointSet.empty()) return false;
    return (prev(pointSet.end())->y - pointSet.begin()->y) >= D;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, D;
    cin >> N >> D;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        pointList[x].push_back({ x, y });
        xSet.insert(x);
    }

    xList.assign(xSet.begin(), xSet.end());

    int j = -1, minVal = MAX_INT + 1;
    for (size_t i = 0; i < xList.size(); i++) {
        while (j + 1 < (int)xList.size()) {
            if (satisfied(D)) {
                minVal = min(minVal, xList[j] - xList[i]);
                break;
            }
            addPoint(xList[++j]);
        }
        removePoint(xList[i]);
    }

    cout << (minVal == MAX_INT + 1 ? -1 : minVal) << "\n";

    return 0;
}
