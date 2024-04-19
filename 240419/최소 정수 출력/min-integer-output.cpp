#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<int> q;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (num == 0) {
			if (q.empty()) {
				cout << "0\n";
			}
			else {
				int a = -q.top();
				q.pop();

				cout << a << "\n";
			}

		}
		else {
			q.push(-num);
		}


	}
}