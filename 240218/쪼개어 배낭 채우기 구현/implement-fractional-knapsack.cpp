#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    double A = (double)a.second / a.first;
    double B = (double)b.second / b.first;
    return A < B;
}

int main() {
    cout << fixed;
    cout.precision(3);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> v;

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end(), compare);

    double ans = 0;
    while (m > 0 && v.size() > 0) {
        int a = v[v.size() - 1].first; 
        int b = v[v.size() - 1].second;
        if (m >= a) {
            ans += b;
            m -= a;
        }
        else {
            ans += (double)b / a * m;
            m = 0;
        }
        v.pop_back();
    }
    cout << ans;
}