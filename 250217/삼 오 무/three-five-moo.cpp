#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

long long n;

long long Calc(long long mid) {
	long long moo_cnt = mid / 3 + mid / 5 - mid / 15;

	return mid - moo_cnt;
}

int main() {
	cin >> n;

	long long left = 1;
	long long right = INT_MAX;
	long long min_num = INT_MAX;

	while (left <= right) {
		long long mid = (left + right) / 2;

		if (Calc(mid) >= n) {
			right = mid - 1;
			min_num = min(mid, min_num);
		}
		else {
			left = mid + 1;
		}
	}

	cout << min_num;
}