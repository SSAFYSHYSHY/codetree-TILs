#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v;

void Print() {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
}

void Calc(int num, int cnt) {
	if (num == n+1) {
		if (cnt == m) {
			Print();
		}
		return;
	}

	v.push_back(num);
	Calc(num + 1 , cnt + 1);
	v.pop_back();

	Calc(num + 1, cnt);
}

int main() {
	cin >> n >> m;

	Calc(1, 0);
}