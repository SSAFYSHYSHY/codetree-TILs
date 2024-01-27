#include <iostream>
#include <queue>
#include <string>

using namespace std;

priority_queue<int> q;

int n;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;

		if (s == "push") {
			int a;
			cin >> a;

			q.push(a);
		}
		else if (s == "size") {
			cout << q.size() << "\n";
		}
		else if (s == "pop") {
			cout << q.top() << "\n";
			q.pop();
		}
		else if (s == "empty") {
			if (q.empty()) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else if (s == "top") {
			cout << q.top() << "\n";
		}
	}
}