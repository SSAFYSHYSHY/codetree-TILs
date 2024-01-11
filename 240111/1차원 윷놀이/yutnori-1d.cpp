#include <iostream>
#include <vector>

using namespace std;

int n, m, k, ans = 0, cnt = 0;
int arr[13];
int brr[4];

int Calc2() {
	int sum = 0;
	for (int i = 0; i < k; i++) {
		sum += (brr[i] >= m);
	}

	return sum;
}

void Calc(int num) {
    
	ans = max(ans, Calc2());
	
    if (num == n) {
		return;
	}

	for (int i = 0; i < k; i++) {
		if (brr[i] >= m) continue;

		brr[i] += arr[num];
		Calc(num + 1);
		brr[i] -= arr[num];
	}
}

int main() {
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < k; i++) {
		brr[i] = 1;
	}

	Calc(0);

	cout << ans;
}