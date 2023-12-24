#include <iostream>

using namespace std;

int N;
int arr[3] = {0,};
int a[101], b[101], c[101];

int main() {

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}

	int ans = 0;
	for (int i = 0; i < 3; i++) {
		int cnt = 0;
		arr[i] = 1;

		for (int j = 0; j < N; j++) {
			swap(arr[a[j]], arr[b[j]]);

			if (arr[c[j]] == 1) {
				cnt++;
			}
		}

		arr[i] = 0;
		ans = max(ans, cnt);
	}
	cout << ans;
}