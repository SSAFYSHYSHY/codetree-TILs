#include <iostream>

using namespace std;

int a, b, c;
int ans = 0;
int a_n, b_n;

bool Calc(int num) {

	if (num > c) return false;

	return true;
}

int main() {
	cin >> a >> b >> c;

	a_n = c / a;
	b_n = c / b;


	int num = 0, num1 = 0;
	for (int i = 0; i <= a_n; i++) {
		num = 0;

		for (int j = 0; j <= b_n; j++) {
			num = (i * a) + (j * b);

			if(Calc(num)){
				num1 = max(num1, num);
			}
		}
	}
	cout << num1;
}