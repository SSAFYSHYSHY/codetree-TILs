#include <iostream>
#include <algorithm>

using namespace std;

int n, k = 17;
int arr[1001];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int ans = 21e8;
	for (int i = 0; i <= 100; i++) {
		int cnt = 0;

		for(int j = 0 ; j < n ; j++) {
			if(arr[j] < i) {
				cnt += (arr[j] - i) * (arr[j] - i);
			}
			if(arr[j] > i + k) {
				cnt += (arr[j] - i - k) * (arr[j] - i - k);
			}
		}

		ans = min(ans, cnt);

	}

	cout << ans;
}