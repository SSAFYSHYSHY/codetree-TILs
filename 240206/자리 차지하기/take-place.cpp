#include <iostream>
#include <set>

using namespace std;

int n, m;
set<int> s;

int main() {
	cin >> n >> m;

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
				break;
				
			}
			else {
				continue;
			}
		}

		if (flag == false) {
			cout << s.size();
			return 0;
		}
	}
}