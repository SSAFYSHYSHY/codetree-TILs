#include <iostream>

using namespace std;

int n, m;
int arr[1000001];
int brr[1000001];

int main() {
	cin >> n >> m;

	int t_a = 1;
	for (int i = 0; i < n; i++) {
		int a;
		char b;

		cin >> a >> b;

		while (a--) {
			if (b == 'R') {
				arr[t_a] = arr[t_a - 1] + 1;
			}
			else {
				arr[t_a] = arr[t_a - 1] - 1;
			}

			t_a++;
		}
	}

	int t_b = 1;
	for (int i = 0; i < m; i++) {
		int a;
		char b;

		cin >> a >> b;

		while (a--) {
			if (b == 'R') {
				brr[t_b] = brr[t_b - 1] + 1;
			}
			else {
				brr[t_b] = brr[t_b - 1] - 1;
			}

			t_b++;
		}
	}

	if (t_a < t_b) {
		for (int i = t_a; i < t_b; i++) {
			arr[i] = arr[i - 1];
		}
	}
	else if (t_a > t_b) {
		for (int i = t_b; i < t_a; i++) {
			brr[i] = brr[i - 1];
		}
	}

	int cnt = 0;
	int t_max = 0;

	if (t_a < t_b) {
		t_max = t_b;
	}
	else {
		t_max = t_a;
	}

	for (int i = 1; i < t_max; i++) {
		if (arr[i] == brr[i] && arr[i - 1] != brr[i - 1]) {
			cnt++;
		}
	}

	cout << cnt;
}