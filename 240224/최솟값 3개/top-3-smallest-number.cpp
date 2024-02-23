#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    priority_queue<long long, vector<long long>, greater<long long>> q;

    for (long long i : arr) {
        q.push(i);
        if (q.size() < 3) {
            cout << -1 << endl;
        } else {
            long long a = q.top();
            q.pop();
            long long b = q.top();
            q.pop();
            long long c = q.top();
            q.pop();
            cout << (long long)(a * b * c) << endl;
            q.push(a);
            q.push(b);
            q.push(c);
        }
    }

    return 0;
}