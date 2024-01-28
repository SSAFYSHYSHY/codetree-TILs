#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int arr[100001];
double ans;

int main() {
	cout << fixed;
	cout.precision(2);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int k = 0; k < n - 2; k++) {

		priority_queue<int, vector<int>, greater<int>> q;
		int len = 0;
		double sum = 0;

		for (int j = k  +  1 ; j < n; j++) {
			q.push(arr[j]);
		}

		q.pop();
		len = q.size();

		while (!q.empty()) {
			int a = q.top();
			sum += a;
			q.pop();
		}
		sum = sum / len;

		ans = max(ans, (double)sum);

	}

	cout << ans;
}