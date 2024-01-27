#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> q;

int n;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;

		if (a == 0) {
			if (q.empty()) {
				cout << "0\n";
			}
			else {
				cout << q.top() << "\n";
				q.pop();
			}
		}
		else {
			q.push(a);
		}
	}
}