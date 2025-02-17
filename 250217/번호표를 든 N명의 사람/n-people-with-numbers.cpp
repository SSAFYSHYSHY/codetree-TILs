#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, t_max;
int d[100001];

bool Calc(int mid) {
	priority_queue<int> q;

	for (int i = 0; i < mid; i++) {
		q.push(-d[i]);
	}

	for (int i = mid; i < n; i++) {
		int curr_time = -q.top();
		q.pop();

		q.push(-(curr_time + d[i]));
	}

	int end_time = 0;
	while (!q.empty()) {
		end_time = max(end_time, -q.top());
		q.pop();
	}

	return end_time <= t_max;
}

int main() {
	cin >> n >> t_max;

	for (int i = 0; i < n; i++) {
		cin >> d[i];
	}

	int left = 1;
	int right = n;
	int ans = n;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (Calc(mid)) {
			right = mid - 1;
			ans = min(ans, mid);
		}
		else {
			left = mid + 1;
		}
	}

	cout << ans;
}