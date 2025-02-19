#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long arr[50005];

int Calc(long long n) {
	long long cnt = 1;

	for (;;) {
		n /= 10;
		if (n == 0) break;

		cnt *= 10;
	}

	return cnt;
}

bool cmp(long long a, long long b) {
	long long num1 = Calc(a);
	long long num2 = Calc(b);

	long long n1 = a * 10 * num2 + b;
	long long n2 = b * 10 * num1 + a;

	if (n1 > n2) return true;
	else return false;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n, cmp);

	for (int i = 0; i < n; i++) {
		cout << arr[i];
	}
}