#include <iostream>
#include <algorithm>

using namespace std;

long long s;

int main() {
	cin >> s;

	long long left = 1;
	long long right = 2000000000;
	long long min_num = 0;

	while (left <= right) {
		long long mid = (left + right) / 2;

		if (mid * (mid + 1) / 2 <= s) {
			left = mid + 1;
			min_num = max(min_num, mid);
		}
		else {
			right = mid - 1;
		}
	}
	
	cout << min_num;

}