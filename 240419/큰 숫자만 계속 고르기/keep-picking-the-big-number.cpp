#include <iostream>
#include <queue>

using namespace std;

int n, m;
priority_queue<int> q;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		q.push(a);
	}

	while (m--) {
		int num = q.top();
		q.pop();

		num--;
		

		q.push(num);
	}

	cout << q.top();
}