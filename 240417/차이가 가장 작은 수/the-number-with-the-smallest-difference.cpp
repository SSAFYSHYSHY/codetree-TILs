#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int n, m;
int ans = 21e8;
int arr[100001];
set<int> s;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		s.insert(arr[i]);
	}

	for (int i = 0; i < n; i++) {
		int x = arr[i];

		if (s.lower_bound(x + m) != s.end()) {
			ans = min(ans, *s.lower_bound(m + x) - x);
		}

		set<int>::iterator it = s.upper_bound(x - m);

		if (it != s.begin()) {
			it--;
			ans = min(ans, x - *it);
		}
	}

	if (ans == 21e8) {
		ans = -1;
	}
	cout << ans;

}