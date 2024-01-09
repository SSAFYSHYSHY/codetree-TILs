#include <iostream>
#include <vector>

using namespace std;

int n, ans = 21e8;
int arr[11][11];
bool visited[11];
vector<int> v;

int Calc2() {
	int sum = 0;
	int x = 1, y = 0;
	for (int i = 0; i < v.size(); i++) {
		y = v[i];
		sum += arr[x][y];

		x = y;
	}

	return sum;
}

void Calc(int num) {
	if (v.size() == n) {
		if (v[v.size() - 1] != 1) {
			return;
		}

		// for (int i = 0; i < v.size(); i++) {
		// 	cout << v[i] << " ";
		// }
		// cout << "\n";

		ans = min(ans, Calc2());
	}

	for (int i = 1; i <= n; i++) {
		if (arr[num][i] == 0) continue;

		if (visited[i] == true) continue;

		visited[i] = true;
		v.push_back(i);

		Calc(i);

		v.pop_back();
		visited[i] = false;
	}
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	Calc(1);

	cout << ans;
}