#include <iostream>

using namespace std;

int n, p, num = 1, cnt = 0;

int main() {
	cin >> n >> p;
	num = n;

	while (1) {
		num *= n;

		cnt++;
		if (num == n) {
			break;
		}

		num %= p;
	}

	cout << cnt;
}