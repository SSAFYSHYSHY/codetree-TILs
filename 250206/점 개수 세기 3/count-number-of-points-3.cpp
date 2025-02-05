#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> points(n);
    vector<pair<int, int>> queries(q);
    set<int> unique_nums;

    // 좌표 입력
    for (int i = 0; i < n; i++) {
        cin >> points[i];
        unique_nums.insert(points[i]);
    }

    // 쿼리 입력
    for (int i = 0; i < q; i++) {
        cin >> queries[i].first >> queries[i].second;
        unique_nums.insert(queries[i].first);
        unique_nums.insert(queries[i].second);
    }


    unordered_map<int, int> mapper;
    int idx = 1;
    for (int num : unique_nums) {
        mapper[num] = idx++;
    }


    vector<int> freq(idx, 0);  // 압축 좌표 개수 저장
    for (int x : points) {
        freq[mapper[x]]++;
    }


    vector<int> prefix_sum(idx, 0);
    for (int i = 1; i < idx; i++) {
        prefix_sum[i] = prefix_sum[i - 1] + freq[i];
    }


    for (auto& [l, r] : queries) {
        int left = mapper[l];
        int right = mapper[r];
        cout << prefix_sum[right] - prefix_sum[left - 1] << "\n";
    }

    return 0;
}