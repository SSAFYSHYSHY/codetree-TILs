#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;


vector<tuple<int, int, int>> v;
int dp[1001];
int n;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int s, e, p;
		cin >> s >> e >> p;
		v.push_back(make_tuple(s, e, p));
		dp[i] = p;
	}

	sort(v.begin(), v.end());

	int price;
	tie(ignore, ignore, price) = v[0];
	dp[0] = price;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			int x;
			int y1;
			int price;

			tie(x, ignore, price) = v[i];

			tie(ignore, y1, ignore) = v[j];

			if (x > y1) {
				dp[i] = max(dp[i], dp[j] + price);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[i]);
	}

	cout << ans;

}