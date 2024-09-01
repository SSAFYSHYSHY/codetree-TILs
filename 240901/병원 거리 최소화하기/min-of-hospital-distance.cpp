#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

vector<pair<int, int>> custom;
vector<pair<int, int>> hospital;
vector<int> v;

int n, m, ans = 0;
int arr[51][51];
bool visited[13] = { false, };
int mini = 21e8, cnt = 0;

void Back(int idx, int now)  {
	if (now == m) {
		int num = 21e8;
		ans = 0;

		for (int i = 0; i < custom.size(); i++) {
			int cx = custom[i].first;
			int cy = custom[i].second;
			int sum = 0, num = 21e8;

			for (int j = 0; j < v.size(); j++) {
				int x = hospital[v[j]].first;
				int y = hospital[v[j]].second;

				sum = abs(cx - x) + abs(cy - y);

				num = min(num, sum);
				

			}

			ans += num;

		}

		mini = min(mini, ans);
		return;
	}

	for (int i = idx; i < cnt; i++) {
		if (!visited[i]) {
			visited[i] = true;
			v.push_back(i);
			Back(i+1, now + 1);
			v.pop_back();
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			

			if (arr[i][j] == 1) {
				custom.push_back(make_pair(i, j));
			}
			else if (arr[i][j] == 2) {
				hospital.push_back(make_pair(i, j));
				cnt++;
			}
		}
	}

	Back(0,0);

	cout << mini;
}