#include <iostream>
#include <set>

using namespace std;

int n, m;
int arr[100001];
set<int> s;

int main() {
	cin >> n >> m;

	for(int i = 0; i < n ;i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= m; i++) {
		s.insert(i);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		//ai 보다 큰 위치를 먼저 찾음.
		set<int>::iterator it = s.upper_bound(arr[i]);

		//만약 큰 최초의 위치가 첫 번째 위치가 아니라면,
		//바로 전위치가 ai 보다 같거나 작은 최대 위치가 구해지므로,
		//해당 위치에 사람을 앉혀줌.
		if (it != s.begin()) {
			it--;
			s.erase(*it);

			ans++;
		}
		else {
			break;
		}
	}

	cout << ans;
}