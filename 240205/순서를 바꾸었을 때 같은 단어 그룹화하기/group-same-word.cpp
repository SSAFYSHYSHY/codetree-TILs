#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;
unordered_map<string, int> v;
string arr[1001];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		sort(arr[i].begin(), arr[i].end());

		v[arr[i]]++;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (v[arr[i]] > ans) {
			ans = v[arr[i]];
		}
	}

	cout << ans;


}