#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <tuple>

using namespace std;

int n, p,l;
int m;

set<pair<int,int>> s;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		s.insert(make_pair(y, x));
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		string ss;
		cin >> ss;

		if (ss == "ad") {
			int x, y;
			cin >> x >> y;

			s.insert(make_pair(y, x));
		}
		else if (ss == "sv") {
			int x, y;
			cin >> x >> y;

			s.erase(make_pair(y,x));
		}
		else if (ss == "rc") {
			int num;
			cin >> num;

			if (num == 1) {
				int p, l;
				tie(l, p) = *s.rbegin();

				cout << p << "\n";
			}
			else {
				int p, l;
				tie(l, p) = *s.begin();

				cout << p << "\n";

			}
		}
	}
}