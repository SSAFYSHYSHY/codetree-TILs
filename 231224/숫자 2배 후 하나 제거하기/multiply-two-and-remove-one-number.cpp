#include <iostream>
#include <cmath>

using namespace std;

int n, ans = 21e8;
int arr[101];
int new_arr[101];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	//첫 완탐, 숫자 두배.
	for (int i = 0; i < n; i++) {
		arr[i] *= 2;
		
		//한개 제외하고 인접 수들 모조리 합의 차.
		for (int j = 0; j < n; j++) {
			int cnt = 0;
			new_arr[n] = {};
			
			for (int k = 0; k < n; k++) {
				if (k != j) {
					new_arr[cnt++] = arr[k];
				}
			}

			int diff = 0;
			for (int k = 0; k < n - 2; k++) {
				diff += abs(new_arr[k] - new_arr[k+1]);
			}

			ans = min(ans, diff);
		}

		arr[i] /= 2;
	}
	
	cout << ans;
}