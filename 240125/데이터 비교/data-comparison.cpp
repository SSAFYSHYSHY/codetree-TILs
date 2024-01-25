#include <algorithm>
#include <iostream>
#include <unordered_set>
#include<vector>

using namespace std;

unordered_set<int> v;
unordered_set<int> v1;
int n, m;
int arr[100001];
int arr1[100001];
vector<int> ans;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		v.insert(arr[i]);
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> arr1[i];
		v1.insert(arr1[i]);
	}

	for (int i = 0; i < m; i++) {
		if (v.find(arr1[i]) == v.end()) {
			ans.push_back(0);
		}
		else {
			ans.push_back(1);
		}
	}


	for (int i = 0; i < m; i++) {
		cout << ans[i] << " ";
	}

}