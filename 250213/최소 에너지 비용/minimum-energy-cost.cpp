#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long arr[100001];  // 도시간 거리
long long cost[100001]; // 도시별 주유 가격

int main() {
    cin >> n;

    for (int i = 1; i <= n - 1; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }

    long long min_cost = cost[1]; // 최소 주유 비용 (첫 번째 도시의 비용으로 초기화)
    long long real_ans = 0;

    for (int i = 1; i <= n - 1; i++) {
        min_cost = min(min_cost, cost[i]);  // 현재까지의 최소 기름값 유지
        real_ans += min_cost * arr[i];  // 현재 거리만큼 최소 비용으로 이동
    }

    cout << real_ans << '\n';
    return 0;
}