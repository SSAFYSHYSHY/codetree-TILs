#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[100002];
int office[100002];
int ans = 0;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> office[i];
	}

	sort(arr, arr + n);
	sort(arr, arr + m);

	int j = 0;
	for (int i = 0; i < m; i++) {
		while (j < n) {
			
			if (i < m - 1) {
				if (abs(office[i] - arr[j]) <= abs(office[i + 1] - arr[j])) {
					ans = max(ans, abs(office[i] - arr[j]));
					j++;
				}
				else {
					break;
				}
			}

			else {
				ans = max(ans, abs(office[i] - arr[j]));
				j++;
			}
		}
	}

	cout << ans;
}