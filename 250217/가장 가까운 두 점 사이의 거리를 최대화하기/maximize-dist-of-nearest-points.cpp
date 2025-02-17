#include <iostream>
#include <algorithm>
#include <tuple>

#define MAX_N 100000

using namespace std;

int n;
pair<int, int> segments[MAX_N];

bool Calc(int mid) {
	int curr_x;
	tie(curr_x, ignore) = segments[0];

	for (int i = 1; i < n; i++) {
		int x1, x2;
		tie(x1, x2) = segments[i];

		if (x2 < curr_x + mid) {
			return false;
		}

		curr_x = max(curr_x + mid, x1);
	}

	return true;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x1, x2;
		cin >> x1 >> x2;

		segments[i] = make_pair(x1, x2);
	}
	sort(segments, segments + n);
	
	int left = 1;
	int right = 1e9;
	int ans = 0;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (Calc(mid)) {
			left = mid + 1;
			ans = max(ans, mid);
		}
		else {
			right = mid - 1;
		}
	}

	cout << ans;

}