#include <iostream>
#include <set>

using namespace std;

set<int> v;
int m, n;
int arr[100001];

int main() {
	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		arr[i] = i;
		v.insert(arr[i]);
	}

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.erase(a);

		cout << *v.rbegin() << "\n";

	}

}