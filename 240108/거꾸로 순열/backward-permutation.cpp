#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;
bool visited[9];

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

	for (int i = n; i >= 1; i--) {
		if (visited[i]) continue;

		visited[i] = true;
		v.push_back(i);

		Calc(num + 1);

		v.pop_back();
		visited[i] = false;
	}
}

int main() {
	cin >> n;

	Calc(0);
}