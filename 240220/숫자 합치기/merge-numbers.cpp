#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<int> v;
priority_queue<int, vector<int>, greater<int>> q;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		q.push(num);
	}

	int ans = 0;

	while (q.size() > 1) {
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();
		int sum = a + b;
		ans += sum;
		q.push(sum);
	}

	cout << ans;
}