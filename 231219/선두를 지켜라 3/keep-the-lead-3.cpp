#include <iostream>

using namespace std;

int a, b;
int arr[1001], brr[1001];
int cnt = 0, flag = 0;

int main() {
	cin >> a >> b;

	int a_num = 1;
	for (int i = 0; i < a; i++) {
		int v, t;

		cin >> v >> t;

		while (t--) {
			arr[a_num] = arr[a_num - 1] + v;
			a_num++;
		}
	}

	int b_num = 1;
	for (int i = 0; i < b; i++) {
		int v, t;

		cin >> v >> t;

		while (t--) {
			brr[b_num] = brr[b_num - 1] + v;
			b_num++;
		}
	}

	for (int i = 2; i <= a_num; i++) {
		if (arr[i] > brr[i]) {
			if (flag == 2 || flag == 3) {
				cnt++;
			}

			flag = 1;
		}
		else if (arr[i] < brr[i]) {
			if (flag == 1 || flag == 3) {
				cnt++;
			}

			flag = 2;
		}
		else if (arr[i] == brr[i]) {
			if (flag == 2 || flag == 1) {
				cnt++;
			}

			flag = 3;
		}
	}

	cout << cnt;
}