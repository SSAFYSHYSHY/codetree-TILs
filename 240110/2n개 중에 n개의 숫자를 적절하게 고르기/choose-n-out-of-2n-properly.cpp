#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int arr[22];
int n, m ,ans = 21e8;
bool visited[22];

int Calc2() {
	int sum = 0;
	int sum2 = 0;

	for (int i = 0; i < 2 * n; i++) {
		if (visited[i]) {
			sum += arr[i];
		}
		else {
			sum2 += arr[i];
		}
	}

	return abs(sum - sum2);

}

void Calc(int curr, int cnt) {
	if (cnt == n) {
		ans = min(ans, Calc2());
		return;
	}

	if (curr == 2 * n) {
		return;
	}

	Calc(curr + 1, cnt);

	visited[curr] = true;
	Calc(curr + 1, cnt + 1);
	visited[curr] = false;
}

int main() {
	cin >> n;

	for (int i = 0; i < 2 * n; i++) {
		cin >> arr[i];
	}

	Calc(1, 0);

	cout << ans;
}