#include <iostream>
#include <queue>

using namespace std;

int n;
int arr[100001];
priority_queue<int> pq;
int ans = 0;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		pq.push(-arr[i]);
	}

	while (pq.size() > 1) {
		int x1 = pq.top(); pq.pop();
		int x2 = pq.top(); pq.pop();

		x1 = -x1;
		x2 = -x2;

		ans += (x1 + x2);
		pq.push(-(x1 + x2));
	}

	cout << ans;
}