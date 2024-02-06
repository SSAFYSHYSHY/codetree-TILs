#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int n, p, num = 1, cnt = 0, ans = 0;

bool Simul() {
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.size(); j++) {
			if (v[i] == v[j]) {
				ans = j - i;
				return true;
			}
		}
	}
	return false;
}

int main() {
	cin >> n >> p;
	num = n;

	while (1) {
		num *= n;

		num %= p;
		
		v.push_back(num);

		if (Simul()) {
			break;
		}
		else {
			continue;
		}
	}

	cout << ans;

}