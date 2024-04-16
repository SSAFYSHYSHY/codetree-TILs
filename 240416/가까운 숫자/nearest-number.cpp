#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int n, ans = 21e8;
set<int> s;
int arr[100001];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	s.insert(0);

	for (int i = 0; i < n; i++) {
		set<int>::iterator it = s.upper_bound(arr[i]);

		if (it != s.end()) {
			ans = min(ans, *it - arr[i]);
		}
		it--;

		ans = min(ans, arr[i] - *it);

		s.insert(arr[i]);

		cout << ans << "\n";
	}


}