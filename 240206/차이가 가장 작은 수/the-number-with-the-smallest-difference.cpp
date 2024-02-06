#include <iostream>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

set<int> s;
int arr[100001];
int n, m;
int ans = INT_MAX;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		s.insert(arr[i]);
	}

	for (int i = 0; i < n; i++) {
		//arr[i] 보다 낮은 위치를 찾음.
		for (auto it = next(s.lower_bound(arr[i])); it != s.end(); it++) {
			int sub = abs(arr[i] - *it);

			if (sub >= m) {
				ans = min(ans, sub);
			}
		}

	}

    if(ans == INT_MAX) {
        cout << -1;
    }
    else {
        cout << ans;
    }
}