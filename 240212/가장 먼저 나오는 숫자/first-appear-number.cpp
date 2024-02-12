#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr, q;

int binary_search(int target) {
    int left = 0;
    int right = n - 1;
    int idx = n;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            idx = min(idx, mid);
        }

        if (arr[mid] >= target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return idx;
}

int main() {
    cin >> n >> m;
    arr.resize(n);
    q.resize(m);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < m; ++i) {
        cin >> q[i];
    }

    for (int i = 0; i < m; ++i) {
        int idx = binary_search(q[i]);
        cout << (idx != n ? idx + 1 : -1) << endl;
    }

    return 0;
}