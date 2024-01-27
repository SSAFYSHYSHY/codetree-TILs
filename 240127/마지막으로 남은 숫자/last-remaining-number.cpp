#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int n;
priority_queue<int> q;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		q.push(a);
	}

	while (q.size() >= 2) {
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();

		if (a == b) {
			continue;
		}
		else {
			int c = abs(a - b);
			q.push(c);
		}
	}

	if (q.empty()) {
		cout << -1;
		return 0;
	}
	cout << q.top();
}