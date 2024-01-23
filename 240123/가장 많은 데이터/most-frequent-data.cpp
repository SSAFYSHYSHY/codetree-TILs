#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, int> v;
string arr[100001];
int n;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
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