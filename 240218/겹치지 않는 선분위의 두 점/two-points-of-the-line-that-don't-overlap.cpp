#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> a;

bool is_possible(int dist) {
    int cnt = 1;
    int last = a[0];
    for (int i = 1; i < a.size(); ++i) {
        if (a[i] - last >= dist) {
            last = a[i];
            cnt += 1;
        }
    }
    return cnt >= n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int start, end;
        cin >> start >> end;
        for (int elem = start; elem <= end; ++elem) {
            a.push_back(elem);
        }
    }
    
    sort(a.begin(), a.end());
    
    int left = 1;
    int right = 1000000000;
    int ans = -1;
    
    while (left <= right) {
        int mid = (left + right) / 2;
        if (is_possible(mid)) {
            left = mid + 1;
            ans = mid;
        } else {
            right = mid - 1;
        }
    }
    
    cout << ans << endl;

    return 0;
}