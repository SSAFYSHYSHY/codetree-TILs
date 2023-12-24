#include <iostream>

using namespace std;

int arr[101];
int temp[101];
int m , n;

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		temp[i] = arr[i];
	}

	int ans = 0;
	//n 번 순회. 1번 완탐.
	for (int i = 1; i <= n; i++) {
		//초기화 및 copy;
		for (int i = 1; i <= n; i++) {
			temp[i] = arr[i];
		}

		int sum = 0;
		
		//위치변환에 필요한 idx 초기값은 순환 순서.;
		int idx = i;

		//2번 완탐, m 번 진행.
		for (int j = 0; j < m; j++) {
			sum += temp[idx];

			idx = temp[idx];
		}

		ans = max(sum, ans);
	}
	cout << ans;
}