#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

int n, k;
int a[100001];
int b[100001];

int arr[100001];
int ans[100001];

unordered_set<int> v[100001];

int main() {
	cin >> n >> k;

	for (int i = 0; i < k; i++) {
		cin >> a[i] >> b[i];
	}

	for (int i = 1; i <= n; i++) {
		arr[i] = i;
		v[i].insert(i);
		ans[i] = 1;
	}

	for (int t = 0; t < 3; t++) {
		for (int i = 0; i < k; i++) {
			swap(arr[a[i]], arr[b[i]]);

			if (v[arr[a[i]]].find(a[i]) == v[arr[a[i]]].end()) {
				v[arr[a[i]]].insert(a[i]);
				ans[arr[a[i]]]++;
			}
			if (v[arr[b[i]]].find(b[i]) == v[arr[b[i]]].end()) {
				v[arr[b[i]]].insert(b[i]);
				ans[arr[b[i]]]++;
			}

		}
	}

	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " \n";
	}


}