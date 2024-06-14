#include <iostream>
#define MAX_A 1000000

using namespace std;

int arr[100001] = {0,};
int prefix[1000001];
int n, q, maxi = 0;

int Sum(int s, int e) {
	if (s == 0) return prefix[e];
	return prefix[e] - prefix[s - 1];
}

int main() {
	cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		prefix[arr[i]]++;
	}


	for (int i = 1; i <= MAX_A; i++) {
		prefix[i] += prefix[i - 1];
	}

	for (int t = 0; t < q; t++) {
		int x, y;
		cin >> x >> y;
		cout << Sum(x, y) << "\n";
	}
}