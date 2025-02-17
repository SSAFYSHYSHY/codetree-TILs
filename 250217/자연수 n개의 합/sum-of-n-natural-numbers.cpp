#include <iostream>
#include <algorithm>
#define MAX_S 2000000000

using namespace std;

long long s;

int main() {
	cin >> s;

	long long left = 1;
	long long right = MAX_S;
	long long max_num = 0;

	while (left <= right) {
		long long mid = (left + right) / 2;

		if (mid * (mid + 1) / 2 <= s) {
			left = mid + 1;
			max_num = max(max_num, mid);
		}
		else {
			right = mid - 1;
		}
	}

	cout << max_num;
}