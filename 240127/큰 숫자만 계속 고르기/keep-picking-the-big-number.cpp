#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> q;
int n , m;

int main() {
	cin >> n >> m;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		q.push(a);
	}

	for (int i = 0; i < m; i++) {
		int b = q.top();
		b -= 1;

		q.pop();
		q.push(b);
	}

	cout << q.top();
}