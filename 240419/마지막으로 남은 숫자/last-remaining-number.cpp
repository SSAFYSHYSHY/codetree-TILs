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

	while (q.size() >= 2) {

		int x, x1;
		x = q.top();
		q.pop();

		x1 = q.top();
		q.pop();

        if(abs(x - x1) != 0) {
		    q.push(abs(x - x1));
        }
	}

    if(q.size() == 1) {
        cout << q.top();
    }
    else {
        cout << -1;
    }
}