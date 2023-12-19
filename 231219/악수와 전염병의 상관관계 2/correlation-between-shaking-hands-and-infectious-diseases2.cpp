#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int n, k, p, t;
vector<pair<int, pair<int, int>>> v;
int arr[101];
int cnt[101];

bool comp(const pair<int, pair<int, int>>& a, const pair<int, pair<int, int>>& b) {
	return a.first > b.first;
}

int main() {
	cin >> n >> k >> p >> t;

	for (int i = 0; i < t; i++) {
		int time, x, y;

		cin >> time >> x >> y;

		v.push_back(make_pair(time, make_pair(x, y)));
	}

	sort(v.begin(), v.end(), comp);

	arr[p] = 1;
	for (int i = 0; i < t; i++) {
		//데이터 팝.
		int time, x, y;
		time = v.back().first;
		x = v.back().second.first;
		y = v.back().second.second;
		v.pop_back();

		//만약 바이러스에 감염된 사람이 x,y좌표일 경우.
		if (arr[x] == 1 && arr[y] == 0) {
			if (cnt[x] >= k) {
				continue;
			}
			else {
				cnt[x]++;
				arr[y] = 1;
				continue;
			}
		}
		if (arr[y] == 1 && arr[x] == 0) {
			if (cnt[y] >= k) {
				continue;
			}
			else {
				cnt[y]++;
				arr[x] = 1;
				continue;
			}
		}
		if (arr[x] == 1 && arr[y] == 1) {
			if (cnt[x] >= k && cnt[y] >= k) continue;

			else {
				cnt[x]++;
				cnt[y]++;
				continue;
			}
		}
	}

	// for (int i = 1; i <= n; i++) {
	// 	cout << arr[i] << " ";
	// }
	// cout << "\n";
	// for (int i = 1; i <= n; i++) {
	// 	cout << cnt[i] << " ";
	// }
	// cout << "\n";

	for (int i = 1; i <= n; i++) {
		cout << arr[i];
	}
}