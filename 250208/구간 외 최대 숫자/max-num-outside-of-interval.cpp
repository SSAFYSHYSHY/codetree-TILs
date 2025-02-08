#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    vector<int> arr(n + 1);
    vector<int> L(n + 1, 0), R(n + 2, 0);

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    // L[i]: 1~i-1까지의 최댓값
    for (int i = 1; i <= n; i++) {
        L[i] = max(L[i - 1], arr[i]);
    }

    // R[i]: i+1~n까지의 최댓값
    for (int i = n; i >= 1; i--) {
        R[i] = max(R[i + 1], arr[i]);
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << max(L[l - 1], R[r + 1]) << "\n";
    }

    return 0;
}