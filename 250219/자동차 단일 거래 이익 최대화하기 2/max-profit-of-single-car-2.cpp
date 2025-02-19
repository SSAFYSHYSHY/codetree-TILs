#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

int Calc(const vector<int>& v) {
	if (v.empty()) return 0;

	int min_prices = v[0];
	int max_profit = 0;

	for (int i = 1; i < v.size(); i++) {
		max_profit = max(max_profit, v[i] - min_prices);
		min_prices = min(min_prices, v[i]);
	}

	return max_profit;
}

int main() {
	cin >> n;

	vector<int> v;

	for(int i = 0; i < n ; i++) {
		int num;
		cin >> num;

		v.push_back(num);
	}

	cout << Calc(v) << "\n";
}