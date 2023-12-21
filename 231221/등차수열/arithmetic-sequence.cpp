#include <iostream>

using namespace std;

int n;
int arr[101];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int ans = 0;
	for (int t = 1; t <= 100; t++) {
		int cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (((arr[i] + arr[j])/2) == t && ((arr[i] + arr[j]) % 2) == 0) {
					//cout << arr[i] << " " << t << " " << arr[j] << "\n";

					cnt++;
				}
			}
		}

		ans = max(ans, cnt);
	}

	cout << ans;
}