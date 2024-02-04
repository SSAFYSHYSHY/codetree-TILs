#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int n, k;
unordered_map<int, int> v;
vector<int> arr;

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}

	for (int i = 0; i < n; i++) {
		v[arr[i]]++;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int sum = arr[i] + arr[j];

			if (v.find(k - sum) == v.end()) {
				continue;
			}
			if (k - sum == arr[i]) {
				ans -= 1;
			}
			if (k - sum == arr[i]) {
				ans -= 1;
			}

			ans += v[k - sum];
		}
	}

	cout << ans / 3;
}