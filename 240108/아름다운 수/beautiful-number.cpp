#include <iostream>
#include <vector>

using namespace std;

int n, cnt = 0;
vector<int> v;

bool Same() {
	for (int i = 0; i < n; i += v[i]) {
		//연속해서 해당 숫자 만큼 나오지 않는 다면.
		if (i + v[i] - 1 >= n) {
			return false;
		}

		//연속해서 해당 숫자 있는지 판단. 하나라도 다른 수가 있다면 제외.
		for (int j = i; j < i + v[i]; j++) {
			if (v[j] != v[i]) {
				return false;
			}
		}
	}

	return true;


}

void Calc(int num) {
	if (num == n) {
		if (Same()) {
			cnt++;
		}

		return;
	}

	for (int i = 1; i <= 4; i++) {
		v.push_back(i);
		Calc(num + 1);
		v.pop_back();
	}
}

int main() {
	cin >> n;

	Calc(0);

	cout << cnt;
}