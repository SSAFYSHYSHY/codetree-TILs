#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 절댓값과 원래의 값을 함께 저장하는 우선순위 큐

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;

        if (x != 0) {
            pq.push({abs(x), x}); // 절댓값과 원래의 값을 함께 우선순위 큐에 추가
        } else {
            if (pq.empty()) {
                cout << "0\n"; // 배열이 비어 있는 경우
            } else {
                cout << pq.top().second << "\n"; // 가장 작은 값의 원래의 값을 출력
                pq.pop(); // 가장 작은 값 제거
            }
        }
    }

    return 0;
}