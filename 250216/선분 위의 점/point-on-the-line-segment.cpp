#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[100001];

int Upper(int target) {
	int left = 0, right = n - 1, min_idx = n;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (arr[mid] > target) {
			right = mid - 1;
			min_idx = min(min_idx, mid);
		}
		else {
			left = mid + 1;
		}
	}

	return min_idx;
}

int Lower(int target) {
	int left = 0, right = n - 1, min_idx = n;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (arr[mid] >= target) {
			right = mid - 1;
			min_idx = min(min_idx, mid);
		}
		else {
			left = mid + 1;
		}
	}

	return min_idx;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		int cnt = Upper(b) - Lower(a);

		cout << cnt << "\n";
	}
}