#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 폭탄 정보를 저장하는 구조체
struct Bomb {
    int score, time_limit;
};

// 정렬 기준: 시간 제한이 짧은 순으로 정렬
bool cmp(const Bomb &a, const Bomb &b) {
    return a.time_limit < b.time_limit;
}

int maxBombScore(int n, vector<Bomb>& bombs) {
    // 시간 제한이 짧은 순으로 정렬
    sort(bombs.begin(), bombs.end(), cmp);

    priority_queue<int> pq;  // 최대 힙 (점수가 높은 폭탄을 우선 선택)
    int totalScore = 0;
    int time = 0;

    for (const Bomb &bomb : bombs) {
        if (time < bomb.time_limit) {
            // 해체 가능하면 우선 큐에 추가하고 시간 증가
            pq.push(bomb.score);
            totalScore += bomb.score;
            time++;
        } else if (!pq.empty() && pq.top() < bomb.score) {
            // 더 높은 점수의 폭탄이 있으면 교체 (최적화)
            totalScore += bomb.score - pq.top();
            pq.pop();
            pq.push(bomb.score);
        }
    }

    return totalScore;
}

int main() {
    int n;
    cin >> n;

    vector<Bomb> bombs(n);
    for (int i = 0; i < n; i++) {
        cin >> bombs[i].score >> bombs[i].time_limit;
    }

    cout << maxBombScore(n, bombs) << endl;
    return 0;
}
