#include <iostream>

using namespace std;

int arr[101];
int temp[101] = {0,};
int n, s, e;

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 2; i++) {
		cin >> s >> e;

		for (int j = 1; j <= n; j++) {
			temp[j] = 0;
		}

		for (int j = s; j <= e; j++) {
			arr[j] = 0;
		}

		int cnt = 1;
		for (int j = 1; j <= n; j++) {
			if (arr[j] != 0) {
				temp[cnt] = arr[j];
				cnt++;
			}
		}

		for (int j = 1; j <= n; j++) {
			arr[j] = temp[j];
		}
	}

	int cnt2 = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[i] != 0) cnt2++;
	}
	cout << cnt2 << "\n";
	for (int i = 1; i <= cnt2; i++) {
		cout << arr[i] << "\n";
	}


}