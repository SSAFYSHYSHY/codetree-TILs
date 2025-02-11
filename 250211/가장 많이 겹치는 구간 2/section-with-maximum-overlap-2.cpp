#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

long long n, maxi = 0, mini = LLONG_MAX;
map<long long, long long> visited; // 배열 대신 map 사용
pair<long long, long long> arr[100001];

void Input() {
    cin >> n;
    for (long long i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;

        arr[i] = { x, y };
    }
}

int main() {
    Input();

    for (long long i = 0; i < n; i++) {
        long long x = arr[i].first, y = arr[i].second;

        maxi = max(maxi, y);
        mini = min(mini, x);

        visited[x] += 1;
        visited[y] -= 1;
    }

    long long sum = 0, ans = 0;
    for (auto it = visited.begin(); it != visited.end(); ++it) {
        sum += it->second;
        ans = max(ans, sum);
    }

    cout << ans;
}