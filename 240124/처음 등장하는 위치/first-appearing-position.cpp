#include <iostream>
#include <map>

using namespace std;

int arr[100001];
int n;
map<int, int> v;

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		if (v[arr[i]] != 0) {
			continue;
		}
		else {
			v[arr[i]] = i;
		}
	}

	map<int, int>::iterator it;

	for (it = v.begin(); it != v.end(); it++) {
		cout << it->first << " " << it->second << "\n";
	}


}