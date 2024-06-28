#include <iostream>
#include <algorithm>

using namespace std;

int arr[100001];
int n;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int j = n - 1;
	int ans = 21e8;
	for (int i = 0; i < n; i++) {
		if (i < j) {
			ans = min(ans, abs(arr[i] + arr[j]));
		}

		while (i < j - 1 && arr[i] + arr[j] > 0) {
			j--;
			ans = min(ans, abs(arr[i] + arr[j]));
		}
	}

	cout << ans;
}