#include <iostream>
#include <vector>
#include<unordered_set>
#include <climits>
using namespace std;

int n;
int arr[100001];
unordered_set<int> v;
unordered_set<int> v1;
vector<int> ans;

int minn = INT_MAX, maxn = INT_MIN;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		v.insert(arr[i]);
		if (arr[i] > maxn) {
			maxn = arr[i];
		}
		if (arr[i] < minn) {
			minn = arr[i];
		}

	}

	int cnt = 0;
	for (int i = minn; i <= maxn; i++) {
		if (v.find(i) != v.end()) {
			//cout << "yes\n";
			cnt++;
		}
	}

	cout << cnt;
}