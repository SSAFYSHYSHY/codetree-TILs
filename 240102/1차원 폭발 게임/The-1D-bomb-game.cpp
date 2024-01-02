#include <iostream>

using namespace std;

int arr[101];
int temp[101];
int n, m, len, temp_len;

int Calc(int x, int num) {
	int ex = x + 1;

	while (ex < len) {
		if (arr[ex] == num) {
			ex++;
		}
		else {
			break;
		}
	}

	return ex - 1;
}

void Calc2(int sx, int ex) {
	for (int i = sx; i <= ex; i++) {
		arr[i] = 0;
	}
}

void Calc3() {
	temp_len = 0;

	for (int i = 0; i < len; i++) {
		if (arr[i] != 0) {
			temp[temp_len++] = arr[i];
		}
	}
}

void Calc4() {
	len = temp_len;

	for (int i = 0; i < len; i++) {
		arr[i] = temp[i];
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	len = n;

	bool flag;
	do {
		flag = false;

		for (int i = 0; i < len; i++) {
			if (arr[i] == 0) {
				continue;
			}

			int j = Calc(i, arr[i]);

			if (j - i + 1 >= m) {
				Calc2(i, j);
				flag = true;
			}
		}

		Calc3();

		Calc4();


	} while (flag);

	cout << len << "\n";
	for (int i = 0; i < len; i++) {
		cout << arr[i] << "\n";
	}
}