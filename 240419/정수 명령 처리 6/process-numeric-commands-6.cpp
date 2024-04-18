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
			int num;
			cin >> num;

			q.push(num);
		}
		else if (s == "size") {
			cout << q.size() << "\n";
		}
		else if (s == "empty") {
			if (!q.empty()) {
				cout << "0\n";
			}
			else {
				cout << "1\n";
			}
		}
		else if (s == "pop") {
			int num;
			num = q.top();

			cout << num << "\n";
			q.pop();
		}
		else if (s == "top") {
			cout << q.top() << "\n";
		}
	}
}