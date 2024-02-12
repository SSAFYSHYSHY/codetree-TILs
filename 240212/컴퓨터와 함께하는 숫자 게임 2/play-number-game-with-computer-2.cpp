#include <iostream>
#include <algorithm>

using namespace std;

long long m, a, b;
long long min_num = 21e8;
long long max_num = 0;

long long Calc(int num) {
	long long left = 1;
	long long right = m;
	long long cnt = 0;

	while (left <= right) {
		cnt++;
		long long mid = (left + right) / 2;

		if (mid == num) {
			break;
		}

		if (mid > num) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}

	return cnt;
}

int main() {
	cin >> m >> a >> b;

	for (int i = a; i <= b; i++) {
		min_num = min(min_num, Calc(i));
		max_num = max(max_num, Calc(i));
	}

	cout << min_num << " " << max_num;
}