#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, sum = 0;
int arr[100001];
double ans,avg;
priority_queue<int>q;

int main() {
	cout << fixed;
	cout.precision(2);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

    
    sum += arr[n];
    q.push(-arr[n]);

	for (int k = n-2; k >= 1 ; k--) {
        sum += arr[k + 1];
        q.push(-arr[k + 1]);

		double avg = (double)(sum - (-q.top())) / (n - k - 1);
		ans = max(ans, avg);

	}

	cout << ans;
}