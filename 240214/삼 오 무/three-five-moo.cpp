#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

long long n;

long long Calc(long long mid) {
	return mid - (mid / 3) - (mid / 5 )+ (mid / 15);
}

int main() {
	cin >> n;

	long long left = 1;
	long long right = 2000000000;
	long long min_num = 2000000000;

	while (left <= right) {
		long long mid = (left + right) / 2;

		if (Calc(mid) >= n) {
			right = mid - 1;
			min_num = min(min_num, mid);
		}
		else if(Calc(mid) < n){
			left = mid + 1;
		}
	}

	cout << min_num;

}