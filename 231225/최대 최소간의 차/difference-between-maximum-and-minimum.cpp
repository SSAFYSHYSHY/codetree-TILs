#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int arr[101];

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int mini = 21e8;
	for (int i = 1; i <= 10000; i++) {
		int cnt = 0;

		for (int j = 0; j < n; j++) {
			if (i <= arr[j] && arr[j] <= i + k) {
				continue;
			}
			else if (arr[j] < i) {
				cnt += i - arr[j];
			}
			else {
				cnt += arr[j] - (i + k);
			}
		}

		mini = min(mini, cnt);
	}

	cout << mini;
}