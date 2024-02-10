#include <iostream>

using namespace std;

int arr[100001];
int n, m, idx = -1;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int num = 0;
	for (int i = 0; i < m; i++) {
		cin >> num;
		int left = 0, right = n - 1;
		idx = -1;
		bool flag = false;

		while (left <= right) {
			int mid = (left + right) / 2;

			if (arr[mid] == num) {
				flag = true;
				idx = mid;
				break;
			}

			if (arr[mid] > num) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}

		if (flag) {
			cout << idx+1 << "\n";
		}
		else {
			cout << -1 << "\n";
		}
	}
}