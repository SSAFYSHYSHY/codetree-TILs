#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int n, m;
int arr[100001];
int brr[100001];

unordered_set<int> v;
unordered_set<int> v1;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		v.insert(arr[i]);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> brr[i];
		v1.insert(brr[i]);
	}

	vector<int> ans;
	for (int i = 0; i < m; i++) {
		if (v.find(brr[i]) != v.end()) {
			ans.push_back(1);
		}
		else {
			ans.push_back(0);
		}
	}

	for (int i = 0; i < m; i++) {
		cout << ans[i] << "\n";
	}
}