#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int n, ans = 0;
int arr[4][5001];

unordered_map<int, int> v;
unordered_map<int, int> v1;

int main() {
	cin >> n;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//1 + 2
			v[arr[0][i] + arr[1][j]]++;

			//3 + 4
			v1[arr[2][i] + arr[3][j]]++;
		}
	}

	for (unordered_map<int, int>::iterator it = v.begin(); it != v.end(); it++) {
		int sub = -(it->first);
		if (v1.find(sub) != v1.end()) {
			ans += v1[sub] * (it->second);
		}
	}

	cout << ans << "\n";

}