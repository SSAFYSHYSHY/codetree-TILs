#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> v;
int n, k;
int arr[100001];

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		v[i] = arr[i];
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i+1; j < n; j++) {
			sum = v[i] + v[j];

			if (sum == k) {
				cnt++;
				sum = 0;
			}
		}
	}
	cout << cnt;
}