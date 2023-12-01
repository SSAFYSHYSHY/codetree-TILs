#include <iostream>

using namespace std;

int n, m, arr_end, temp_end;
int arr[101];
int temp[101];

int Calc(int start, int num) {
	int end = start + 1;
	while (end < arr_end) {
		if (arr[end] == num) {
			end++;
		}
		else {
			break;
		}
	}

	return end - 1;
}

void Calc2(int s, int e) {
	for (int i = s; i <= e; i++) {
		arr[i] = 0;
	}
}

void Calc3() {
	temp_end = 0;

	for (int i = 0; i < arr_end; i++) {
		if (arr[i] != 0) {
			temp[temp_end++] = arr[i];
		}
	}
}

void Copy() {
	arr_end = temp_end;

	for (int i = 0; i < arr_end; i++) {
		arr[i] = temp[i];
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	arr_end = n;

	bool flag;
	do {
		flag = false;

		for (int i = 0; i < arr_end; i++) {
			if (arr[i] == 0) {
				continue;
			}

			int end_idx = Calc(i, arr[i]);

			if (end_idx - i + 1 >= m) {
				Calc2(i, end_idx);
				flag = true;
			}
		}

		Calc3();
		Copy();

	} while (flag);

	cout << arr_end << "\n";

	for (int i = 0; i < arr_end; i++) {
		cout << arr[i] << "\n";
	}
}