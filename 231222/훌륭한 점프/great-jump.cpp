#include <iostream>

using namespace std;

int n, m;
int arr[10001];

bool Calc(int num) {
	int idx = 0;

	for (int i = 1; i < n; i++) {
		if (arr[i] <= num) {
			if (i - idx > m) {
				return false;
			}
			idx = i;
		}
	}

	return true;
}

int main() {
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int min_ans = 21e8;
	for (int i = max(arr[0], arr[n - 1]); i <= 100; i++) {
		if (Calc(i)) {
			cout << i;
			break;
		}
	}

}