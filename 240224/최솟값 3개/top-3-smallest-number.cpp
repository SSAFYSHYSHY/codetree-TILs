#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    priority_queue<int, vector<int>, greater<int>> q;

    for (int i : arr) {
        q.push(i);
        if (q.size() < 3) {
            cout << -1 << endl;
        } else {
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            int c = q.top();
            q.pop();
            cout << a * b * c << endl;
            q.push(a);
            q.push(b);
            q.push(c);
        }
    }

    return 0;
}