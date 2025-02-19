#include <iostream>
#include <set>
#include <tuple>
#include <vector>
#include <algorithm>

#define MAX_C 100000

using namespace std;

// 변수 선언
int c, n;

int red_stones[MAX_C];
set<int> red_s;
vector<pair<int, int> > black_stones;

int main() {
    // 입력:
    cin >> c >> n;
    for (int i = 0; i < c; i++)
        cin >> red_stones[i];

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        black_stones.push_back(make_pair(b, a));
    }

    for (int i = 0; i < c; i++)
        red_s.insert(red_stones[i]);

    sort(black_stones.begin(), black_stones.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        tie(b, a) = black_stones[i];
        if (red_s.lower_bound(a) != red_s.end()) {
            int ti = *red_s.lower_bound(a);
            if (ti <= b) {
                ans++;
                red_s.erase(ti);
            }
        }
    }
    cout << ans;
    return 0;
}
