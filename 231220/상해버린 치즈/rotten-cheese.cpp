#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, d, s, ans =0;
vector<pair<int, int>> eat[51];
int sick[51];

int main() {
	cin >> n >> m >> d >> s;

	for (int i = 0; i < d; i++) {
		int p, c, t;
		cin >> p >> c >> t;

		eat[p].push_back(make_pair(c, t));
	}

	for (int i = 0; i < s; i++) {
		int p, t;
		cin >> p >> t;

		sick[p] = t;
	}

	for (int i = 1; i <= m; i++) {
		int count[51] = {0,};

		for (int j = 1; j <= n; j++) {
			
			for (int k = 0; k < eat[j].size(); k++) {

				if (eat[j][k].first == i) {
					count[j] = eat[j][k].second + 1;
				}
			}
		}

		int cnt = 0;
		bool flag = false;

		for (int j = 1; j <= n; j++) {
			if (count[j] > 0) {
				if (sick[j] > count[j] - 1 || sick[j] == 0) {
					cnt++;
				}
				else if (sick[j] <= count[j] - 1) {
					flag = true;
					break;
				}
			}
			else if (count[j] == 0 && sick[j] > 0) {
				flag = true;
				break;
			}
		}
		if (flag) continue;

		ans = max(ans, cnt);

	}

	cout << ans;
}