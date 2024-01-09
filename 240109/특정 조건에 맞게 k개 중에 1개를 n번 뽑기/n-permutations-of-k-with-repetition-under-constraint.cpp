#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector<int> v;

bool Same() {
	int cnt = 1;

	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i] == v[i + 1]) {
			cnt++;
		}
		else {
			cnt = 1;
		}

		if (cnt >= 3) {
			return false;
		}
	}

	return true;
}

void Calc(int dir) {
	if (dir == n + 1) {
		if (Same()) {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i] << " ";
			}
			cout << "\n";

		}
		return;
	}

	for (int i = 1; i <= k; i++) {

		v.push_back(i);
		Calc(dir + 1);
		v.pop_back();
	}
}

int main() {
	cin >> k >> n;

	Calc(1);
}