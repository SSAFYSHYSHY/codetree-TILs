#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int n, q;
vector<pair<int, int>> points;
vector<tuple<int, int, int, int>> queries;

// 좌표 압축 매핑
map<int, int> x_mapper, y_mapper;
vector<vector<int>> BIT;  // Fenwick Tree (BIT)

// 좌표 압축 수행
void compress_coordinates() {
    set<int> x_set, y_set;

    // 모든 x, y 좌표를 set에 저장 (중복 제거 + 정렬)
    for (auto& [x, y] : points) {
        x_set.insert(x);
        y_set.insert(y);
    }
    for (auto& [sx, sy, ex, ey] : queries) {
        x_set.insert(sx);
        x_set.insert(ex);
        y_set.insert(sy);
        y_set.insert(ey);
    }

    // 압축된 좌표 부여
    int idx = 1;
    for (int x : x_set) x_mapper[x] = idx++;
    int max_x = idx;  // 압축된 X 좌표 최대 크기

    idx = 1;
    for (int y : y_set) y_mapper[y] = idx++;
    int max_y = idx;  // 압축된 Y 좌표 최대 크기

    // Fenwick Tree 크기 조정 (압축된 크기만큼만 할당)
    BIT.assign(max_x + 1, vector<int>(max_y + 1, 0));
}

// Fenwick Tree (BIT) 업데이트
void update(int x, int y, int delta) {
    for (int i = x; i < BIT.size(); i += (i & -i)) {
        for (int j = y; j < BIT[0].size(); j += (j & -j)) {
            BIT[i][j] += delta;
        }
    }
}

// Fenwick Tree (BIT)에서 (1,1) ~ (x,y)까지의 합 계산
int queryBIT(int x, int y) {
    int sum = 0;
    for (int i = x; i > 0; i -= (i & -i)) {
        for (int j = y; j > 0; j -= (j & -j)) {
            sum += BIT[i][j];
        }
    }
    return sum;
}

// (sx, sy) ~ (ex, ey) 범위의 점 개수 구하기
int get_range_sum(int sx, int sy, int ex, int ey) {
    return queryBIT(ex, ey) - queryBIT(sx - 1, ey) - queryBIT(ex, sy - 1) + queryBIT(sx - 1, sy - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    points.resize(n);
    queries.resize(q);

    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    for (int i = 0; i < q; i++) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        queries[i] = {sx, sy, ex, ey};
    }

    // 좌표 압축 수행
    compress_coordinates();

    // Fenwick Tree에 점 추가
    for (auto& [x, y] : points) {
        update(x_mapper[x], y_mapper[y], 1);
    }

    // 질의 처리
    for (auto& [sx, sy, ex, ey] : queries) {
        int sx_mapped = x_mapper[sx];
        int sy_mapped = y_mapper[sy];
        int ex_mapped = x_mapper[ex];
        int ey_mapped = y_mapper[ey];

        cout << get_range_sum(sx_mapped, sy_mapped, ex_mapped, ey_mapped) << "\n";
    }

    return 0;
}