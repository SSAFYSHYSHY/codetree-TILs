#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> v;
vector<pair<int, int>>v1;
int n, m;
int ans = 21e8;

bool Calc2() {

	// 1. 초기 숫자 세팅.
	int num1[11];
	int num2[11];
	for (int i = 0; i < n; i++) {
		num1[i] = num2[i] = i;
	}

	//2. 위에서부터 순서대로 가로줄에 대해 양쪽 번호를 교환한다.

	for (int i = 0; i < (int)v.size(); i++) {
		int idx = v[i].second;
		swap(num1[idx], num1[idx + 1]);
	}

	for (int i = 0; i < (int)v1.size(); i++) {
		int idx = v1[i].second;
		swap(num2[idx], num2[idx + 1]);
	}

	//3 . 동일한지 파악.
	for (int i = 0; i < n; i++) {
		if (num1[i] != num2[i]) {
			return false;
		}
	}

	return true;
}

void Calc(int num) {
	if (num == m) {
		if (Calc2()) {
			ans = min(ans, (int)v1.size());
		}
		return;
	}

	v1.push_back(v[num]);
	Calc(num + 1);
	v1.pop_back();

	Calc(num + 1);
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		v.push_back(make_pair(a, b - 1));
	}

	sort(v.begin(), v.end());

	Calc(0);
	
	cout << ans;
}