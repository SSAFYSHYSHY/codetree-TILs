#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

int n, ans = 0;
int arr[16][16];
vector<pair<int, int>> v;
pair<int, int> p[16];

bool Calc3(pair<int, int> p1, pair<int, int> p2) {
	int ax1, ax2;
	tie(ax1, ax2) = p1;

	int bx1, bx2;
	tie(bx1, bx2) = p2;

	return (ax1 <= bx1 && bx1 <= ax2) || (ax1 <= bx2 && bx2 <= ax2) ||
		(bx1 <= ax1 && ax1 <= bx2) || (bx1 <= ax2 && ax2 <= bx2);
}

bool Calc2() {
	for (int i = 0; i < (int)v.size(); i++) {
		for (int j = i + 1; j < (int)v.size(); j++) {
			if (Calc3(v[i], v[j])) {
				return false;
			}
		}
	}

	return true;
}

void Calc(int num) {
	if (num == n) {
		if (Calc2()) {
			ans = max(ans, (int)v.size());
		}
		return;
	}

	v.push_back(p[num]);
	Calc(num + 1);

	v.pop_back();

	Calc(num + 1);
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x1, x2;
		cin >> x1 >> x2;

		p[i] = make_pair(x1, x2);
	}

	Calc(0);

	cout << ans;
}