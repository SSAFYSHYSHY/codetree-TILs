#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int arr[4][8];
bool flag[5] = {false,};
int dir_arr[4] = {0,};
int k;
int num, dir;

int check[4][2] = {
	{2,8},
	{2,6},
	{2,6},
	{8,6}
};

void Initial() {
	for (int i = 0; i < 5; i++) {
		flag[i] = false;
	}
}

void Check(int num, int num2, int swi) {
	if (flag[num] == false) {
		return;
	}

	int a = check[num][0];
	int a1 = check[num][1];

	int b = check[num2][0];
	int b1 = check[num2][1];

	if (swi == 0) {
		if (arr[num][a1] == arr[num2][b]) {
			flag[num2] = false;
		}
		else {
			flag[num2] = true;
		}
	}
	else {
		if (arr[num][a] == arr[num2][b1]) {
			flag[num2] = false;
		}
		else {
			flag[num2] = true;
		}
	}
}

void Rotate(int num, int dir) {
	if (dir == -1) {
		int temp = arr[num][0];

		for (int i = 0; i < 8; i++) {
			arr[num][i] = arr[num][i + 1];
		}

		arr[num][7] = temp;
	}
	else {
		int temp = arr[num][7];

		for (int i = 7; i >= 0; i--) {
			arr[num][i] = arr[num][i - 1];
		}

		arr[num][0] = temp;
	}
}

void Calc2(int num, int dir) {
	Rotate(num, dir);

	for (int i = num - 1; i >= 0; i--) {
		if (flag[i] == true && dir == -1) {
			Rotate(i, 1);
		}
		else if(flag[i] == true && dir == 1) {
			Rotate(i, -1);
		}
	}

	for (int i = num + 1; i < 4; i++) {
		if (flag[i] && dir == -1) {
			Rotate(i, 1);
		}
		else if (flag[i] && dir == 1) {
			Rotate(i, -1);
		}
	}
}

void Calc(int num, int dir) {
	//Initial();
	Initial();
	flag[num] = true;

	//Check();
	for (int i = num - 1; i >= 0; i--) {
		Check(i + 1, i, 0);
	}

	for (int i = num + 1; i < 4; i++) {
		Check(i - 1, i, 1);
	}

	//Calc();
	Calc2(num, dir);

}

void Print() {
	cout << "\n";
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

int Sum() {
	//cout << arr[0][0] << " " << arr[1][0] << " " << arr[2][0] << " " << arr[3][0] << "\n";

	return (1 * arr[0][0]) + (2 * arr[1][0]) + (4 * arr[2][0]) + (8 * arr[3][0]);
}

int main() {
	for (int i = 0; i < 4; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < s.length(); j++) {
			arr[i][j] = int(s[j] - '0');
		}
	}

	cin >> k;

	while (k--) {
		cin >> num >> dir;
		num -= 1;

		Calc(num, dir);

		//Print();
	}

	int ans = Sum();
	cout << ans;
}