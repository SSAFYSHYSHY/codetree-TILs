#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[11][11];
bool visited[11];
int n, ans = 0;
vector<int> v;

int Calc2() {
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
	}

	return sum;
}

void Calc(int num) {
	if (num == n) {
		ans = max(ans, Calc2());
		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;

		visited[i] = true;
		v.push_back(arr[num][i]);

		Calc(num + 1);

		v.pop_back();
		visited[i] = false;
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	Calc(0);

	cout << ans;
}