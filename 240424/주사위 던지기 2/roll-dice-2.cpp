#include <iostream>
#include <vector>

using namespace std;

int n, m, ans;

vector<int> v;
bool visited[9] = {false,};

int Sum(){
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
	}

	return sum;
}

void Calc(int now) {
	if (now == n) {
		if (Sum() == m) {
			for (int i = 0; i < v.size(); i++) {
				cout << v[i] << " ";
			}
			cout << "\n";
		}

		return;
	}

	for (int i = 1; i <= 6; i++) {
		v.push_back(i);
		Calc(now+1);
		v.pop_back();
	}
}

int main() {
	cin >> n >> m;

	Calc(0);
}