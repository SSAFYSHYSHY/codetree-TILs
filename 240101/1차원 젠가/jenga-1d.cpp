#include <iostream>

using namespace std;

int arr[101] = {0,};
int n;

void Calc(int s, int e) {
	int temp[101] = {0,}, cnt = 0;

	for (int i = 0; i < n; i++) {
		if (s <= i && i <= e) {
			continue;
		}

		temp[cnt] = arr[i];
		cnt++;
	}

	for (int i = 0; i < n; i++) {
		arr[i] = temp[i];
	}

}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < 2; i++) {
		int x, y;
		cin >> x >> y;

		x--, y--;

		Calc(x, y);
	}

	int len = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] != 0) {
			len++;
		}
	}

	cout << len << "\n";
	for (int i = 0; i < len; i++) {
		cout << arr[i] << "\n";
	}
}