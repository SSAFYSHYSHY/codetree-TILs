#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;

int n, k;
pair<int, int> arr[1000001];

int Calc(int idx) {
	int x;
	tie(x, ignore) = arr[idx];
	return x;
}

int Calc2(int idx) {
	int cnt;
	tie(ignore, cnt) = arr[idx];
	return cnt;
}

int main() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;

		arr[i] = make_pair(y, x);
	}

	sort(arr + 1, arr + n + 1);

	int j = 0, ans = 0 , total = 0;
	for (int i = 1; i <= n; i++) {

		while (j + 1 <= n && Calc(j + 1) - Calc(i) <= 2 * k) {
			total += Calc2(j + 1);
			j++;
		}

		ans = max(ans, total);
		total -= Calc2(i);
	}

	cout << ans;
}