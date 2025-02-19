#include <iostream>

using namespace std;

int n;
int arr[2] = { 5,2 };

int main() {
	cin >> n;

	int cnt = 0;
	for (int i = 0; i < 2; i++) {
		cnt += (n / arr[i]);
		n %= arr[i];
	}

	cout << cnt;

}