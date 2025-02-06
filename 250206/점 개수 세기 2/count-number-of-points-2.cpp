#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

#define MAX_N 100000

using namespace std;

// 변수 선언
int n, q;
pair<int, int> points[MAX_N];
tuple<int, int, int, int> queries[MAX_N];

set<int> x_vals, y_vals;
unordered_map<int, int> x_mapper, y_mapper;

// 2D 누적 합 배열
vector<vector<int>> prefix_sum;

void compress_coordinates() {
    for (int i = 0; i < n; i++) {
        x_vals.insert(points[i].first);
        y_vals.insert(points[i].second);
    }
    for (int i = 0; i < q; i++) {
        auto [sx, sy, ex, ey] = queries[i];
        x_vals.insert(sx);
        x_vals.insert(ex);
        y_vals.insert(sy);
        y_vals.insert(ey);
    }

    int x_idx = 1, y_idx = 1;
    for (int x : x_vals) x_mapper[x] = x_idx++;
    for (int y : y_vals) y_mapper[y] = y_idx++;

    prefix_sum.assign(x_idx, vector<int>(y_idx, 0));

    for (int i = 0; i < n; i++) {
        int x = x_mapper[points[i].first];
        int y = y_mapper[points[i].second];
        prefix_sum[x][y]++;
    }

    for (int i = 1; i < x_idx; i++) {
        for (int j = 1; j < y_idx; j++) {
            prefix_sum[i][j] += prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
        }
    }
}

// 특정 구간 [sx, sy] ~ [ex, ey] 내의 점 개수 계산
int get_range_sum(int sx, int sy, int ex, int ey) {
    return prefix_sum[ex][ey]
        - (sx > 1 ? prefix_sum[sx - 1][ey] : 0)
        - (sy > 1 ? prefix_sum[ex][sy - 1] : 0)
        + (sx > 1 && sy > 1 ? prefix_sum[sx - 1][sy - 1] : 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력 받기
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    for (int i = 0; i < q; i++) {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        queries[i] = { sx, sy, ex, ey };
    }

    // 좌표 압축 & 2D 누적 합 준비
    compress_coordinates();

    // 질의 처리
    for (int i = 0; i < q; i++) {
        auto [sx, sy, ex, ey] = queries[i];

        int new_sx = x_mapper[sx];
        int new_sy = y_mapper[sy];
        int new_ex = x_mapper[ex];
        int new_ey = y_mapper[ey];

        cout << get_range_sum(new_sx, new_sy, new_ex, new_ey) << "\n";
    }

    return 0;
}