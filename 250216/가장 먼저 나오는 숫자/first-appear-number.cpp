#include <iostream>

using namespace std;

int n, m;
int arr[100001];

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < m; i++) {
		int left = 1, right = n, min_idx = n + 1;
		int num;

		cin >> num;

		while(left <= right) {
			int mid = (left + right) / 2;

			if (arr[mid] >= num) {
				right = mid - 1;
				min_idx = min(mid, min_idx);
			}
			else {
				left = mid + 1;
			}
		} 

		if (min_idx <= n && arr[min_idx] == num) {
			cout << min_idx << "\n";
		}
		else {
			cout << -1 << "\n";
		}
	}
}