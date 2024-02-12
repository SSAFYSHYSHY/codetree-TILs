#include <iostream>

using namespace std;

int n, m;
int arr[100001];

int LowerBound(int num) {
	int left = 0;
	int right = n - 1;
	int idx = n;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] >= num) {
			right = mid - 1;
			idx = min(idx, mid);
		}
		else {
			left = mid + 1;
		}
	}
	return idx;
}

int UpperBound(int num) {
	int left = 0;
	int right = n - 1;
	int idx = n;

	while (left <= right) {
		int mid = (left + right) / 2;
		if (arr[mid] > num) {
			right = mid - 1;
			idx = min(idx, mid);
		}
		else {
			left = mid + 1;
		}
	}

	return idx;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < m; i++) {
		int x, y;

		cin >> x >> y;

		int a = LowerBound(x);
		int b = UpperBound(y);

		cout << b - a << "\n";
	}
}