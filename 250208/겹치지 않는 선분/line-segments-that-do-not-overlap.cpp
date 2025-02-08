#include <iostream>
#include <algorithm>
#include <tuple>

#define MAX_N 100000

using namespace std;

int n;

pair<int, int> segments[MAX_N];
int L[MAX_N], R[MAX_N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x1, x2;
        cin >> x1 >> x2;
        segments[i] = make_pair(x1, x2);
    }

    sort(segments, segments + n);

    L[0] = segments[0].second;
    for (int i = 1; i < n; i++)
        L[i] = max(L[i - 1], segments[i].second);

    R[n - 1] = segments[n - 1].second;
    for (int i = n - 2; i >= 0; i--)
        R[i] = min(R[i + 1], segments[i].second);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && L[i - 1] >= segments[i].second)
            continue;
        if (i < n - 1 && R[i + 1] <= segments[i].second)
            continue;

        ans++;
    }
    cout << ans;
    return 0;
}
