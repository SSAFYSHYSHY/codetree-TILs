#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<pair<int, int>> v;
int cnt = 0;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		v.push_back(make_pair(x, y));
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int v1[100] = {0,};
				bool flag = false;

				for (int l = 0; l < n; l++) {
					if (l == i || l == j || l == k) continue;

					int x = v[l].first;
					int y = v[l].second;

					for (int i1 = x; i1 <= y; i1++) {
						v1[i1]++;

						if (v1[i1] > 1) flag = true;
					}
				}

				if (!flag) {
					ans++;
				}
			}
		}
	}

	cout << ans;
}