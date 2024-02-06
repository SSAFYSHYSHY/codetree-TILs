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

	// 각 숫자 x 대해
	// x보다 m 이상 더 크면서 가장 작은 값과
	// x보다 m 이상 더 작으면서 가장 큰 값을 구해
	// 차이가 가장 작은 경우를 갱신합니다.
	for (int i = 0; i < n; i++) {
		int x = arr[i];

		// x보다 m 이상 더 크면서 가장 작은 값은
		// r - x >= m를 만족하는 최소 r이므로
		// r >= m + x을 만족하는 최소 r을 구하면 됩니다.
		if (s.lower_bound(m + x) != s.end()) {
			ans = min(ans, *s.lower_bound(m + x) - x);
		}

	   // x보다 m 이상 더 작으면서 가장 큰 값은
	   // x - r >= m를 만족하는 최대 r이므로
	   // r <= x - m을 만족하는 최대 r을 구하면 됩니다.
		set<int>::iterator it = s.upper_bound(x - m);
		if (it != s.begin()) {
			it--;
			ans = min(ans, x - *it);
		}

	}

	if (ans == INT_MAX) {
		cout << -1;
	}
	else {
		cout << ans;
	}
}