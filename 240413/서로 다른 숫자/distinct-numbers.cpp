#include <iostream>
#include <unordered_set>

using namespace std;

int n;
int arr[100001];
unordered_set<int> v;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		v.insert(arr[i]);
	}

	cout << v.size();
}