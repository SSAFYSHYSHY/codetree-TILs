#include <iostream>
#include <unordered_set>

using namespace std;

int n, m;
unordered_set<int> v;
unordered_set<int> v1;

int arr[100001];
int arr2[100001];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr2[i];
		v.insert(arr2[i]);
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
		v1.insert(arr[i]);
	}

	for (int i = 0; i < m; i++) {
		if (v.find(arr[i]) == v.end()) {
			cout << "0 ";
		}
		else {
			cout << "1 ";
		}
	}
}