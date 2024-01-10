#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, ans = 0;
bool visited[21];
int arr[21];

int Calc2() {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (visited[i]) {
			sum ^= arr[i];
		}
	}

	return sum;
}

void Calc(int curr, int cnt) {
	if (cnt == m) {
		ans = max(ans, Calc2());
		return;
	}

	if (curr == n) return;

	Calc(curr + 1, cnt);

	visited[curr] = true;
	Calc(curr + 1, cnt + 1);
	visited[curr] = false;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	Calc(0, 0);

	cout << ans;
}