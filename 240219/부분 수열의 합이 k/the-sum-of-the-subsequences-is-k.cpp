#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> l(n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i];
    }

    vector<int> s(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        s[i] = s[i - 1] + l[i - 1];
    }

    int cnt = 0;
    int j = 0;
    for (int i = 1; i <= n; ++i) {
        while (j < i && s[i] - s[j] > k) {
            ++j;
        }
        if (s[i] - s[j] == k) {
            ++cnt;
        }
    }

    cout << cnt << endl;

    return 0;
}