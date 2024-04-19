#include <iostream>
#include <queue>

using namespace std;

int n, sum = 0;
priority_queue<int> q;
double ans = 0;
int arr[100001];

int main() {
	cout << fixed;
	cout.precision(2);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	q.push(-arr[n - 1]);
	sum += arr[n - 1];


	for (int i = n - 2; i >= 1; i--) {
		q.push(-arr[i]);
		sum += arr[i];

		double avg = (double)(sum - (-q.top())) / (n - i - 1);

		if (ans < avg) {
			ans = avg;
		}
	}

	cout << ans;

}