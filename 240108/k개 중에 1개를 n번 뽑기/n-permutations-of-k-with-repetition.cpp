#include <iostream>
#include <vector>

using namespace std;

int k, n;
vector<int> v;

void Print() {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
}

void Calc(int num) {
	if (num == n) {
		Print();
		return;
	}

	for (int i = 1; i <= k; i++) {
		v.push_back(i);
		Calc(num + 1);
		v.pop_back();
	}
}

int main() {
	cin >> k >> n;

	Calc(0);


}