#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

vector<tuple<double, int ,int>> jewel;

int main() {
	cout << fixed;
	cout.precision(3);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int w, v;
		cin >> w >> v;

		jewel.push_back(make_tuple( -(double)v / w, w, v ));
	}

	sort(jewel.begin(), jewel.end());

	double ans = 0;
	for (int i = 0; i < n; i++) {
		int w, v;
		tie(ignore, w, v) = jewel[i];

		if (m >= w) {
			m -= w;
			ans += v;
		}
		else {
			ans += (double)m / w * v;
			break;
		}
	}

	cout << ans;
}