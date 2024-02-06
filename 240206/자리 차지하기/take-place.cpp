#include <iostream>
#include <set>

using namespace std;

int n, m;
set<int> s;
int cnt = 0;

int main() {
	cin >> n >> m;

	if (n == 1) {
		cout << 1;
		return 0;
	}

	for (int i = 1; i <= m; i++) {
		s.insert(i);
	}

	for (int i = 0; i < n; i++) {
		bool flag = false;
		int a;
		cin >> a;


		for (int j = a; j >= 1; j--) {
			if (s.count(j) == 1) {
				s.erase(j);
				flag = true;
				cnt++;
				break;
				
			}
			else {
				continue;
			}
		}

		if (flag == false) {
			break;
		}
	}

	cout << cnt;
}