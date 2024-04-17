#include <iostream>
#include <set>

using namespace std;

int n, m;
set<int> s;
int arr[100001];

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= m; i++) {
		s.insert(i);
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {

		set<int>::iterator it = s.upper_bound(arr[i]);

		if (it != s.begin()) {
			it--;
			s.erase(*it);

			cnt++;
		}
		else {
			break;
		}
	}

	cout << cnt;
}