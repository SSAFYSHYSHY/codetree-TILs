#include <iostream>
#include <set>
#include <map>
#include <vector>

using namespace std;

int n, q;
vector<pair<int, int>> points;
vector<tuple<int,int,int,int>> queries;

// 좌표 압축용 매핑
map<int, int> x_mapper, y_mapper;
vector<vector<int>> grid;  // 압축된 공간에서 개수 저장
vector<vector<int>> prefix_sum; // 2D 누적 합

void compress_coordinates() {
    set<int> x_set, y_set;

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

    int idx = 1;
    for (int x : x_set) x_mapper[x] = idx++;
    idx = 1;
    for (int y : y_set) y_mapper[y] = idx++;

    int max_x = x_mapper.rbegin()->second;
    int max_y = y_mapper.rbegin()->second;
    grid.assign(max_x + 1, vector<int>(max_y + 1, 0));
    prefix_sum.assign(max_x + 1, vector<int>(max_y + 1, 0));

    for (auto& [x, y] : points) {
        grid[x_mapper[x]][y_mapper[y]]++;
    }

    for (int i = 1; i <= max_x; i++) {
        for (int j = 1; j <= max_y; j++) {
            prefix_sum[i][j] = grid[i][j]
                + prefix_sum[i - 1][j]
                + prefix_sum[i][j - 1]
                - prefix_sum[i - 1][j - 1];
        }
    }
}

int get_range_sum(int sx, int sy, int ex, int ey) {
    return prefix_sum[ex][ey]
        - prefix_sum[sx - 1][ey]
        - prefix_sum[ex][sy - 1]
        + prefix_sum[sx - 1][sy - 1];
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
        queries[i] = {sx, sy, ex, ey };
    }

    compress_coordinates();

    for (auto& [sx, sy, ex, ey] : queries) {  
        int sx_mapped = x_mapper[sx];
        int sy_mapped = y_mapper[sy];
        int ex_mapped = x_mapper[ex];
        int ey_mapped = y_mapper[ey];

        cout << get_range_sum(sx_mapped, sy_mapped, ex_mapped, ey_mapped) << "\n";
    }

    return 0;
}