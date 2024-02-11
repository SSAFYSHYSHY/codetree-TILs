#include <iostream>

using namespace std;

int n,m;
int arr[100001];

//LowerBound는 target 보다 같거나 큰 경우.
int LowerBound(int target) {
	int left = 0;
	int right = n - 1;
	int min_idx = n;

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

//UpperBound는 target 값을 초과하는 숫자.
int UpperBound(int target) {
	int left = 0;
	int right = n - 1;
	int min_idx = n;

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

//UpperBound - LeftBound 는 배열내 숫자의 개수.
//LowerBound와 UpperBound가 같다면 배열 내 값이 없음.

//target보다 같거나, 작은 숫자들이 있는 위치 중 가장 큰 위치를 구하는 함수.

//int CustomBound(int target) {
//	int left = 0;
//	int right = n - 1;
//	int min_idx = -1;
//
//	while (left <= right) {
//		int mid = (left + right) / 2;
//		if (arr[mid] <= target) {
//			left = mid + 1;
//			min_idx = max(min_idx, mid);
//		}
//		else {
//			right = mid - 1;
//		}
//	}
//
//	return min_idx;
//}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;

		int num = UpperBound(a);
		int num1 = LowerBound(a);

		cout << num - num1 << "\n";
	}
}