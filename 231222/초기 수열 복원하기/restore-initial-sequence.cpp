#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1001];
int brr[1001];

int main() {
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		brr[0] = i;

		for (int j = 1; j < n; j++) {
			brr[j] = arr[j - 1] - brr[j - 1];
		}

		bool flag = true;
		bool flag_a[1001] = {};

		for (int j = 0; j < n; j++) {
			if (brr[j] <= 0 || brr[j] > n) {
				flag = false;
			}
			else {
				if (flag_a[brr[j]])
					flag = false;
				flag_a[brr[j]] = true;
			}
		}

		if (flag) {
			for (int j = 0; j < n; j++) {
				cout << brr[j] << " ";
			}
		}
	}
}