#include <iostream>

using namespace std;

int n;
int arr[501];

int main() {
	cin >> n;
	int sum = 0, ans = 0;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 1; j < n; j++) {
			for (int k = 2; k < n; k++) {
				if (((arr[i] & arr[j]) == 0) && ((arr[j] & arr[k]) == 0) && ((arr[i] & arr[k]) == 0)) {
					sum = arr[i] + arr[j] + arr[k];
					ans = max(sum, ans);
				}
			}
		}
	}

	cout << ans;
}