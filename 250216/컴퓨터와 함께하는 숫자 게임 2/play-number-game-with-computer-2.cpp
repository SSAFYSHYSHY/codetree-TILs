#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

long long m;
long long a, b;

int min_ans = INT_MAX;
int max_ans = INT_MIN;

int Get(long long target) {
	long long left = 1;
	long long right = m;
	int cnt = 0;

	while (left <= right) {
		long long mid = (left + right) / 2;
		cnt++;

		if (mid == target) {
			return cnt;
		}
		if (mid > target) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return -1;
}

int main() {
	cin >> m;
	cin >> a >> b;

	for (long long i = a; i <= b; i++) {
		int num = Get(i);

		min_ans = min(min_ans, num);
		max_ans = max(max_ans, num);
	}

	cout << min_ans << " " << max_ans;
}