#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int arr[21][21];
bool visited[21] = { false, };
int n, ans = INT_MAX;

vector<int> v1;
vector<int> v2;

void Calc2() {
	v2.clear();
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			v2.push_back(i);
		}
	}
}

int Calc3() {
	int sum = 0;
	int sum1 = 0;

	for (int i = 0; i < (n/2); i++) {
		for (int j = 0; j < (n / 2); j++) {
			if (v1[i] == v1[j]) continue;

			sum += arr[v1[i]][v1[j]];
		}
	}

	for (int i = 0; i < (n / 2); i++) {
		for (int j = 0; j < (n / 2); j++) {
			if (v2[i] == v2[j]) continue;

			sum1 += arr[v2[i]][v2[j]];
		}
	}

	return abs(sum - sum1);
}

void Calc(int num) {
	if (num == (n / 2)) {
		Calc2();
		ans = min(ans, Calc3());
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			v1.push_back(i);
			visited[i] = true;
			Calc(num + 1);
			visited[i] = false;
			v1.pop_back();
		}
	}
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	Calc(0);

	cout << ans;
}