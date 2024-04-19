#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int n;
priority_queue<int> q;

int main(){
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		q.push(num);
	}

	while (1) {
		if (q.size() == 0) {
			cout << "-1\n";
			return 0;
		}
		else if (q.size() == 1) {
			break;
		}

		int x, x1;
		x = q.top();
		q.pop();

		x1 = q.top();
		q.pop();

		q.push(abs(x - x1));
	}

	cout << q.top() << "\n";
}