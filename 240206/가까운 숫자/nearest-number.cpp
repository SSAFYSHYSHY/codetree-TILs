#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

set<int> s;
int arr[100001];
int n, ans = 21e8;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	s.insert(0);

	for (int i = 0; i < n; i++) {
		//가장 근처에 있는 오른쪽 점을 찾음.
		set<int>::iterator it = s.upper_bound(arr[i]);

		//존재한다면, 거리 중 최소값 갱신.
		if (it != s.end()) {
			ans = min(ans, *it - arr[i]);
		}

		it--;

		ans = min(ans, arr[i] - *it);

		s.insert(arr[i]);

		cout << ans << "\n";
	}
}