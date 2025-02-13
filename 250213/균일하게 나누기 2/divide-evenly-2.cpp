#include <iostream>
#include <algorithm>
#include <tuple>
#include <climits>

using namespace std;

int n;
pair<int, int> points[1001];
int ans = 21e8;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		points[i] = make_pair(x, y);
	}

	sort(points, points + n);

	for (int b = 0; b <= 1000; b += 2) {
		int cnt[1001] = {};

		for (int i = 0; i < n; i++) {
			int y;
			tie(ignore, y) = points[i];

			if (y > b) {
				cnt[1]++;
			}
			else {
				cnt[4]++;
			}
		}

		for (int i = 0; i < n; i++) {
			if (i == 0 || points[i].first != points[i - 1].first) {
				int max_cnt = 0;

				for (int j = 1; j <= 1000; j++) {
					max_cnt = max(max_cnt, cnt[j]);
				}

				ans = min(ans, max_cnt);
			}

			int y;
			tie(ignore, y) = points[i];

			if (y > b) {
				cnt[1]--;
				cnt[2]++;
			}
			else {
				cnt[4]--;
				cnt[3]++;
			}
		}
	}
	cout << ans;
}