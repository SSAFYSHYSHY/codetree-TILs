#include <iostream>

using namespace std;

int n, m;
int arr[100001];

void Input() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
}

int main() {
	Input();

	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;

		int left = 1, right = n, idx = -1;

		while (left <= right) {
			int mid = (left + right) / 2;

			if (arr[mid] == num) {
				idx = mid;
				break;
			}

			//찾는 값이 arr 보다 작다면.
			if (arr[mid] > num) {
				right = mid - 1;
			}
			//찾는 값이 arr보다 크다면.
			else {
				left = mid + 1;
			}
		}

		cout << idx << "\n";
	}

}