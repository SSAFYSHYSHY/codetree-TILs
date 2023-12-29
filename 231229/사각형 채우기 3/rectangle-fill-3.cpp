#include <iostream>
#define num 1000000007

using namespace std;

int n;
long long arr[1001];

int main() {
	cin >> n;

	arr[0] = 1;
	arr[1] = 2;

	for (int i = 2; i <= n; i++) {
        arr[i] = (arr[i-1] * 2 + arr[i-2] * 3) % num;
        for(int j = i - 3 ; j >= 0 ; j--) {
            arr[i] = (arr[i] + arr[j]*2) % num;
        }
	}

	cout << arr[n];
}